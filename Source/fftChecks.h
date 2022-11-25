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
class fftChecks  : public juce::Component
{
public:
    //==============================================================================
    fftChecks ();
    ~fftChecks() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	void makePlots();

	void doSine();

	void fillXFrequency();
	void fillXTime();

	void fillYSin();

	static constexpr double twoPi = 2.0f * numbers::pi;

	enum
	{
		fftOrderAtStart = 10
		, Fs = 48000
	};

	int N = 0;
	static constexpr double Ts = 1.0f / (double)Fs;
	double deltaFreq = 0;

	unique_ptr<juce::dsp::FFT> forwardFFT;

	// Declare plot object.
	cmp::Plot m_plot;

	vector<float> y_data;
	float* fftbfr;

	vector<float> x_ticks;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

