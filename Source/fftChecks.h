/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

#include <numbers>

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
                   private juce::Thread,
                   public juce::Button::Listener
{
public:
    //==============================================================================
    fftChecks ();
    ~fftChecks() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void run() override; // Called from Thread
	//[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	void makePlots();

	void doSine();
	void doFM();

	void fillXFrequency();
	void fillXTime();

	void fillYSin();
	void fillYFM();
	void makeYTickLabels();

	void initNewPlot();
	void resizePlotWindow();

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
	double deltaFreq = ((double)Fs / ((double)N - (double)1));

	float* fftbfr = (float*)calloc(N * 2, sizeof(float));
	vector<float> y_data;
	vector<string> yTickLabels;
	vector<float> x_ticks = vector<float>(N);

	// Carrier
	static constexpr double carrierSinFreq =
		(static_cast<double>(Fs) / static_cast<double>(3));
	static constexpr double carrierSinFreqDeltaRad =
		carrierSinFreq * twoPi * Ts;
	// Signal
	static constexpr double signalSinFreq = 400.0f;
	static constexpr double signalSinFreqDeltaRad =
		signalSinFreq * twoPi * Ts;

	juce::WaitableEvent weDoNextPlot;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> contButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

