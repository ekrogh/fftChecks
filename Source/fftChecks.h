/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

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
class fftChecks  : public juce::Component
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

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Generator)
	};

	Generator<uint64_t> plotCoRoutine();

	Generator<uint64_t> gen = plotCoRoutine();

	/** Called when the user presses the return key. */
	static void textEditorReturnKeyPressed(juce::TextEditor&);
	/** Called when the text editor loses focus. */
	static void textEditorFocusLost(juce::TextEditor&);


	double get_maxTime() { return maxTime; };
	void set_maxTime(double maxTimeVal) { maxTime = maxTimeVal; };

	double get_maxFreq() { return maxFreq; };
	void set_maxFreq(double maxFreqVal) { maxFreq = maxFreqVal; };

	double get_signalSinFreq() { return signalSinFreq; };
	void set_signalSinFreq(double signalSinFreqVal)
	{
		signalSinFreq = signalSinFreqVal;
	};

	double get_carrierSinFreq() { return carrierSinFreq; };
	void set_carrierSinFreq(double carrierSinFreqVal)
	{
		carrierSinFreq = carrierSinFreqVal;
	};

	int get_NTime() { return NTime; };
	void set_NTime(int NTimeVal) { NTime = NTimeVal; };

	double get_Ts() { return Ts; };
	void set_Ts(double TsVal) { Ts = TsVal; };

	int get_NFreq() { return NFreq; };
	void set_NFreq(int NFreqVal) { NFreq = NFreqVal; };

	double get_deltaFreq() { return deltaFreq; };
	void set_deltaFreq(double deltaFreqVal) { deltaFreq = deltaFreqVal; };

	double get_signalSinFreqDeltaRad() { return signalSinFreqDeltaRad; };
	void set_signalSinFreqDeltaRad(double signalSinFreqDeltaRadVal)
	{
		signalSinFreqDeltaRad = signalSinFreqDeltaRadVal;
	};

	double get_twoPi() { return twoPi; };
	void set_twoPi(double twoPiVal) { twoPi = twoPiVal; };

	double get_carrierSinFreqDeltaRad() { return carrierSinFreqDeltaRad; };
	void set_carrierSinFreqDeltaRad(double carrierSinFreqDeltaRadVal)
	{
		carrierSinFreqDeltaRad = carrierSinFreqDeltaRadVal;
	};

	int get_N() { return N; };
	void set_N(int NVal) { N = NVal; };

	int get_Fs() { return Fs; };
	void set_Fs(int FsVal) { Fs = FsVal; };

	int get_fftOrder() { return fftOrder; };
	void set_fftOrder(int fftOrderVal) { fftOrder = fftOrderVal; };

	void updatefftOrderValues();
	void updateFsValues();

	bool get_allIn1ToggleButtonToggleState()
	{
		return allIn1ToggleButtonToggleState;
	};
	void set_allIn1ToggleButtonToggleState(bool allIn1ToggleButtonToggleStateVal)
	{
		allIn1ToggleButtonToggleState = allIn1ToggleButtonToggleStateVal;
	};

	int get_sourceType() { return sourceType; };
	void set_sourceType(int sourceTypeVal) { sourceType = sourceTypeVal; };

	double get_modulationIndex() { return signalAmplitude; };
	void set_modulationIndex(double modulationIndexVal)
	{
		signalAmplitude = modulationIndexVal;
	};

	double get_carrierAmplitude() { return carrierAmplitude; };
	void set_carrierAmplitude(double carrierAmplitudeVal)
	{
		carrierAmplitude = carrierAmplitudeVal;
	};

	bool get_plot_signal() { return plot_signal; };
	void set_plot_signal(bool plot_signalVal)
	{
		plot_signal = plot_signalVal;
	};

	bool get_signal_in_individual_plot() { return signal_in_individual_plot; };
	void set_signal_in_individual_plot(bool signal_in_individual_plotVal)
	{
		signal_in_individual_plot = signal_in_individual_plotVal;
		plot_signal = signal_in_individual_plot || signal_in_combined_plot;
	};

	bool get_signal_in_combined_plot() { return signal_in_combined_plot; };
	void set_signal_in_combined_plot(bool signal_in_combined_plotVal)
	{
		signal_in_combined_plot = signal_in_combined_plotVal;
		plot_signal = signal_in_individual_plot || signal_in_combined_plot;
	};

	bool get_plot_carrier() { return plot_carrier; };
	void set_plot_carrier(bool plot_carrierVal)
	{
		plot_carrier = plot_carrierVal;
	};

	bool get_carrier_in_individual_plot() { return carrier_in_individual_plot; };
	void set_carrier_in_individual_plot(bool carrier_in_individual_plotVal)
	{
		carrier_in_individual_plot = carrier_in_individual_plotVal;
		plot_carrier =  carrier_in_individual_plot || carrier_in_combined_plot;
	};

	bool get_carrier_in_combined_plot() { return carrier_in_combined_plot; };
	void set_carrier_in_combined_plot(bool carrier_in_combined_plotVal)
	{
		carrier_in_combined_plot = carrier_in_combined_plotVal;
		plot_carrier = carrier_in_individual_plot || carrier_in_combined_plot;
	};

	bool get_plot_modulated() { return plot_modulated; };
	void set_plot_modulated(bool plot_modulatedVal)
	{
		plot_modulated = plot_modulatedVal;
	};

	bool get_modulated_in_individual_plot() { return modulated_in_individual_plot; };
	void set_modulated_in_individual_plot(bool modulated_in_individual_plotVal)
	{
		modulated_in_individual_plot = modulated_in_individual_plotVal;
		plot_modulated =  modulated_in_individual_plot || modulated_in_combined_plot;
	};

	bool get_modulated_in_combined_plot() { return modulated_in_combined_plot; };
	void set_modulated_in_combined_plot(bool modulated_in_combined_plotVal)
	{
		modulated_in_combined_plot = modulated_in_combined_plotVal;
		plot_modulated = modulated_in_individual_plot || modulated_in_combined_plot;
	};

	bool get_plot_FFT() { return plot_FFT; };
	void set_plot_FFT(bool plot_FFTVal)
	{
		plot_FFT = plot_FFTVal;
	};

	bool get_FFT_in_individual_plot() { return FFT_in_individual_plot; };
	void set_FFT_in_individual_plot(bool FFT_in_individual_plotVal)
	{
		FFT_in_individual_plot = FFT_in_individual_plotVal;
		plot_FFT =  FFT_in_individual_plot || FFT_in_combined_plot;
	};

	bool get_FFT_in_combined_plot() { return FFT_in_combined_plot; };
	void set_FFT_in_combined_plot(bool FFT_in_combined_plotVal)
	{
		FFT_in_combined_plot = FFT_in_combined_plotVal;
		plot_FFT = FFT_in_individual_plot || FFT_in_combined_plot;
	};

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	void doFillSine();
	void doSineTimeFillPlotData();
	void doSineFFTFillPlotData();
	void doFillFM();
	void doFillAM();
	void doSignalTimeFillPlotData();
	void doCarrierTimeFillPlotData();
	void doFMTimeFillPlotData();
	void doAMTimeFillPlotData();
	void doFMFFTFillPlotData();
	void doAMFFTFillPlotData();

	void fillXFrequency();
	void fillXTime();

	void fillYSignalSin();
	void fillYCarrierSin();
	void fillYFM();
	void fillYAM();
	void hannWinn(float* fftBfrToWin);
	void makeYTickLabels(vector<float>& y_modulated);

	void resizePlots();
	void deleteAllPlots();
	void removeAllPlots();


	int fftOrder = 11;
	int Fs = 48000;

	unique_ptr<juce::dsp::FFT> forwardFFT =
		make_unique<juce::dsp::FFT>(fftOrder);

	// Declare plot object.
	vector<shared_ptr<cmp::Plot> > allPlots;

	double twoPi = (double)2.0f * (double)(numbers::pi);

	int N = forwardFFT->getSize(); // No of points in fft
	double Ts = (double)1.0f / (double)Fs;
	double maxTime = (double)N * Ts;
	int NTime = (int)(maxTime / Ts);

	double deltaFreq = ((double)Fs / ((double)N - (double)1));
	double maxFreq = (double)(Fs >> 1);
	int NFreq = (int)(maxFreq / deltaFreq);


	float* fftbfr = (float*)calloc(N * 2, sizeof(float));



	vector <vector<float>> y_combinedPlots;
	vector <vector<float>> x_combinedPlots;

	vector <vector<float>> y_individualPlots;
	vector <vector<float>> x_individualPlots;

	vector<string> titlePlotsIndividual;
	vector<string> titlePlotsCombined;

	vector<string> yTickLabels;
	vector<float> x_ticksTime;
	vector<float> x_ticksFFT;



	// Carrier
	double carrierSinFreq = 2000.0f;
	double carrierSinFreqDeltaRad =
		carrierSinFreq * twoPi * Ts;
	// Signal
	double signalSinFreq = 400.0f;
	double signalSinFreqDeltaRad =
		signalSinFreq * twoPi * Ts;

	double carrierAmplitude = 1.0f;
	double signalAmplitude = 2.0f;

	bool allIn1ToggleButtonToggleState = true;

	int sourceType = sinSource;


	bool plot_signal = false;
	bool signal_in_individual_plot = false;
	bool signal_in_combined_plot = false;

	bool plot_carrier = false;
	bool carrier_in_individual_plot = false;
	bool carrier_in_combined_plot = false;

	bool plot_modulated = false;
	bool modulated_in_individual_plot = false;
	bool modulated_in_combined_plot = false;

	bool plot_FFT = false;
	bool FFT_in_individual_plot = false;
	bool FFT_in_combined_plot = false;



    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

