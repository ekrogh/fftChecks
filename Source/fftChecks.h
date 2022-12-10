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

#include <numbers>

#include <coroutine>
#include <exception>
#include <iostream>

#include "cmp_plot.h"

using namespace std;



//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	An auto-generated component, created by the Projucer.

	Describe your class and how it works here!
                                                                    //[/Comments]
*/
class fftChecks  : public juce::Component,
                   public juce::Button::Listener
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
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.


	Generator<uint64_t> plotCoRoutine();

	Generator<uint64_t> gen = plotCoRoutine();

	void doSine();
	void doSineTime();
	void doSineFFT();
	void doFM();
	void doFMTime();
	void doFMFFT();

	void fillXFrequency();
	void fillXTime();

	void fillYSin();
	void fillYFM();
	void makeYTickLabels();

	void initNewPlot();
	void resizePlotWindow();
	void deletePlot();

	unique_ptr<juce::dsp::FFT> forwardFFT =
		make_unique<juce::dsp::FFT>(fftOrderAtStart);

	// Declare plot object.
	unique_ptr<cmp::Plot> m_plot;

	static constexpr double twoPi = (double)2.0f * (double)(numbers::pi);

	enum
	{
		fftOrderAtStart = 11
		, Fs = 48000
	};

	int N = forwardFFT->getSize(); // No of points in fft
	static constexpr double Ts = (double)1.0f / (double)Fs;
	double maxTime = (double)N * Ts;

	double deltaFreq = ((double)Fs / ((double)N - (double)1));
	double maxFreq = (double)(Fs >> 1);


	float* fftbfr = (float*)calloc(N * 2, sizeof(float));
	vector<float> y_data;
	vector<string> yTickLabels;
	vector<float> x_ticksTime = vector<float>(N);
	vector<float> x_ticksFFT = vector<float>(N >> 1);

	// Carrier
	static constexpr double carrierSinFreq =
		(static_cast<double>(Fs) / static_cast<double>(3));
	static constexpr double carrierSinFreqDeltaRad =
		carrierSinFreq * twoPi * Ts;
	// Signal
	static constexpr double signalSinFreq = 400.0f;
	static constexpr double signalSinFreqDeltaRad =
		signalSinFreq * twoPi * Ts;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> contButton;
    std::unique_ptr<juce::ToggleButton> _2i2_toggleButton;
    std::unique_ptr<juce::TextEditor> maxTimeTextEditor;
    std::unique_ptr<juce::TextEditor> maxFreqTextEditor;
    std::unique_ptr<juce::Label> macFreqLabel;
    std::unique_ptr<juce::Label> maxTimeLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

