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
class fftChecks : public juce::Component
{
public:
	//==============================================================================
	fftChecks();
	~fftChecks() override;

	//==============================================================================
	//[UserMethods]     -- You can add your own custom methods in this section.
	//[/UserMethods]

	void paint(juce::Graphics& g) override;
	void resized() override;



private:
	//[UserVariables]   -- You can add your own custom variables in this section.

	void fillX();
	void fillYSin();

	static constexpr double twoPi = 2.0f * numbers::pi;

	enum
	{
		fftOrderAtStart = 11
		, N = 2048 // = pow(2, fftOrderAtStart)
	};

	static constexpr double Fs = 44100.0f;
	static constexpr double Ts = 1.0f / Fs;
	static constexpr double deltaFreq = Fs / (N - 1);

	std::unique_ptr<juce::dsp::FFT> forwardFFT = std::make_unique<juce::dsp::FFT>(fftOrderAtStart);

	// Declare plot object.
	cmp::Plot m_plot;

	vector<float> y_data = *(new vector<float>(N));
	float* fftbfr = y_data.data();

	std::vector<float> x_data = *(new vector<float>(N));

	//[/UserVariables]


	//==============================================================================


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(fftChecks)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

