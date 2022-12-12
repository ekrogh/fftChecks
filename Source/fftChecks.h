/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --

#include <JuceHeader.h>

#include <string>

#include <numbers>

#include <coroutine>
#include <exception>
#include <iostream>

#include "cmp_plot.h"

#include "controlPanelDocWin.h"
#include "fftChekGlobalEnums.h"

using namespace std;

class controlPanelDocWin;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	An auto-generated component, created by the Projucer.

	Describe your class and how it works here!
                                                                    //[/Comments]
*/
class fftChecks
	: public juce::Component
{
public:
    //==============================================================================
    fftChecks ();
    ~fftChecks() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	template <typename T>
	struct Generator
	{
		// The class name 'Generator' is our choice and it is not required for coroutine
		// magic. Compiler recognizes coroutine by the presence of 'co_yield' keyword.
		// You can use name 'MyGenerator' (or any other name) instead as long as you include
		// nested struct promise_type with 'MyGenerator get_return_object()' method.
		// Note: You need to adjust class constructor/destructor names too when choosing to
		// rename class.

		struct promise_type;
		using handle_type = std::coroutine_handle<promise_type>;

		struct promise_type
		{ // required
			T value_;
			std::exception_ptr exception_;

			Generator get_return_object()
			{
				return Generator(handle_type::from_promise(*this));
			}
			std::suspend_always initial_suspend() { return {}; }
			std::suspend_always final_suspend() noexcept { return {}; }
			void unhandled_exception() { exception_ = std::current_exception(); } // saving
			// exception

			template <std::convertible_to<T> From> // C++20 concept
			std::suspend_always yield_value(From&& from)
			{
				value_ = std::forward<From>(from); // caching the result in promise
				return {};
			}
			void return_void() {}
		};

		handle_type h_;

		Generator(handle_type h)
			: h_(h)
		{}
		~Generator() { h_.destroy(); }
		explicit operator bool()
		{
			fill(); // The only way to reliably find out whether or not we finished coroutine,
			// whether or not there is going to be a next value generated (co_yield)
			// in coroutine via C++ getter (operator () below) is to execute/resume
			// coroutine until the next co_yield point (or let it fall off end).
			// Then we store/cache result in promise to allow getter (operator() below
			// to grab it without executing coroutine).
			return !h_.done();
		}
		T operator()()
		{
			fill();
			full_ = false; // we are going to move out previously cached
			// result to make promise empty again
			return std::move(h_.promise().value_);
		}

	private:
		bool full_ = false;

		void fill()
		{
			if (!full_)
			{
				h_();
				if (h_.promise().exception_)
					std::rethrow_exception(h_.promise().exception_);
				// propagate coroutine exception in called context

				full_ = true;
			}
		}
	};

	Generator<uint64_t> plotCoRoutine();

	Generator<uint64_t> gen = plotCoRoutine();

	/** Called when the user presses the return key. */
	static void textEditorReturnKeyPressed(juce::TextEditor&);
	/** Called when the text editor loses focus. */
	static void textEditorFocusLost(juce::TextEditor&);


	long double get_maxTime() { return maxTime; };
	void set_maxTime(long double maxTimeVal) { maxTime = maxTimeVal; };

	long double get_maxFreq() { return maxFreq; };
	void set_maxFreq(long double maxFreqVal) { maxFreq = maxFreqVal; };

	long double get_signalSinFreq() { return signalSinFreq; };
	void set_signalSinFreq(long double signalSinFreqVal) { signalSinFreq = signalSinFreqVal; };

	long double get_carrierSinFreq() { return carrierSinFreq; };
	void set_carrierSinFreq(long double carrierSinFreqVal) { carrierSinFreq = carrierSinFreqVal; };

	long double get_NTime() { return NTime; };
	void set_NTime(long double NTimeVal) { NTime = NTimeVal; };

	long double get_Ts() { return Ts; };
	void set_Ts(long double TsVal) { Ts = TsVal; };

	long double get_NFreq() { return NFreq; };
	void set_NFreq(long double NFreqVal) { NFreq = NFreqVal; };

	long double get_deltaFreq() { return deltaFreq; };
	void set_deltaFreq(long double deltaFreqVal) { deltaFreq = deltaFreqVal; };

	long double get_signalSinFreqDeltaRad() { return signalSinFreqDeltaRad; };
	void set_signalSinFreqDeltaRad(long double signalSinFreqDeltaRadVal)
	{
		signalSinFreqDeltaRad = signalSinFreqDeltaRadVal;
	};

	long double get_twoPi() { return twoPi; };
	void set_twoPi(long double twoPiVal) { twoPi = twoPiVal; };

	long double get_carrierSinFreqDeltaRad() { return carrierSinFreqDeltaRad; };
	void set_carrierSinFreqDeltaRad(long double carrierSinFreqDeltaRadVal)
	{
		carrierSinFreqDeltaRad = carrierSinFreqDeltaRadVal;
	};

	long double get_N() { return N; };
	void set_N(long double NVal) { N = NVal; };

	long double get_Fs() { return Fs; };
	void set_Fs(long double FsVal) { Fs = FsVal; };

	long double get_fftOrder() { return fftOrder; };
	void set_fftOrder(long double fftOrderVal) { fftOrder = fftOrderVal; };

	void updatefftOrderValues();
	void updateFsValues();

	bool get_allIn1ToggleButtonToggleState() { return allIn1ToggleButtonToggleState; };
	void set_allIn1ToggleButtonToggleState(long double allIn1ToggleButtonToggleStateVal)
	{
		allIn1ToggleButtonToggleState = allIn1ToggleButtonToggleStateVal;
	};

	int get_sourceType() { return sourceType; };
	void set_sourceType(int sourceTypeVal) { sourceType = sourceTypeVal; };
	
	//[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	void doSine();
	void doSineTime();
	void doSineFFT();
	void doFM();
	void doFMSignalTime();
	void doFMCarrierTime();
	void doFMTime();
	void doFMFFT();

	void fillXFrequency();
	void fillXTime();

	void fillYSignalSin();
	void fillYCarrierSin();
	void fillYFMSignalSin();
	void fillYFM();
	void makeYTickLabels();

	void initNewPlot(plotType toDo);
	void resizePlotWindow();
	void deletePlots();


	int fftOrder = 11;
	int Fs = 48000;

	unique_ptr<juce::dsp::FFT> forwardFFT =
		make_unique<juce::dsp::FFT>(fftOrder);

	// Declare plot object.
	shared_ptr<cmp::Plot> m_plotTimeSignal;
	shared_ptr<cmp::Plot> m_plotTimeCarrier;
	shared_ptr<cmp::Plot> m_plotTimeFM;
	shared_ptr<cmp::Plot> m_plotFFT;
	vector< shared_ptr<cmp::Plot> > allPlots;

	long double twoPi = (long double)2.0f * (long double)(numbers::pi);

	int N = forwardFFT->getSize(); // No of points in fft
	long double Ts = (long double)1.0f / (long double)Fs;
	long double maxTime = (long double)N * Ts;
	int NTime = (int)(maxTime / Ts);

	long double deltaFreq = ((long double)Fs / ((long double)N - (long double)1));
	long double maxFreq = (long double)(Fs >> 1);
	int NFreq = (int)(maxFreq / deltaFreq);


	float* fftbfr = (float*)calloc(N * 2, sizeof(float));
	vector<float> y_data;
	vector<string> yTickLabels;
	vector<float> x_ticksTime;
	vector<float> x_ticksFFT;

	// Carrier
	long double carrierSinFreq =
		(static_cast<long double>(Fs) / static_cast<long double>(3));
	long double carrierSinFreqDeltaRad =
		carrierSinFreq * twoPi * Ts;
	// Signal
	long double signalSinFreq = 400.0f;
	long double signalSinFreqDeltaRad =
		signalSinFreq * twoPi * Ts;

	bool allIn1ToggleButtonToggleState = true;


	int sourceType = sinSource;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

