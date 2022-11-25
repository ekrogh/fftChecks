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

//[Headers] You can add your own extra header files here...
#include <algorithm>
//[/Headers]

#include "fftChecks.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
fftChecks::fftChecks ()
    : N((int)pow((float)2, (float)fftOrderAtStart)),
      deltaFreq((double)Fs / ((double)N - (double)1)),
      m_plot{ cmp::Plot() }
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 800);


    //[Constructor] You can add your own custom stuff here..

	// Add the plot object as a child component.
	addAndMakeVisible(m_plot);

	// Inits
	forwardFFT = make_unique<juce::dsp::FFT>(fftOrderAtStart);
	y_data = *(new vector<float>(N));
	fftbfr = y_data.data(); 
	x_ticks = *(new vector<float>(N));

	// Do the calculations and plots
	makePlots();

    //[/Constructor]
}

fftChecks::~fftChecks()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	//forwardFFT = nullptr;
	//x_ticks = *(new vector<float>());
	//y_data = *(new vector<float>());
	//fftbfr = nullptr;
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void fftChecks::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void fftChecks::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

	// Set the bounds of the plot to fill the whole window.
	m_plot.setBounds(getBounds());

    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void fftChecks::makePlots()
{
	doSine();
}

void fftChecks::doSine()
{
	// Fill the X-axis values
	fillXTime();
	fillYSin();

	// make FFT
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr);

	// Plot some values.
	m_plot.plot({ y_data }, { x_ticks });
}

void fftChecks::fillXFrequency()
{
	int n = 0;
	ranges::generate(x_ticks, [&n, this]() { return (float)(deltaFreq * n++);  });
}

void fftChecks::fillXTime()
{
	int n = 0;
	ranges::generate(x_ticks, [&n, this]() { return (float)(Ts * n++);  });
}

void fftChecks::fillYSin()
{
	//constexpr double sinFreq = 4;
	constexpr double sinFreq = (static_cast<double>(Fs) / static_cast<double>(4));
	constexpr double deltaRad = sinFreq * twoPi * Ts;
	int n = 0;
	ranges::generate
	(
		y_data
		, [&n, &deltaRad, this]()
		{ return  (float)sin(fmod((deltaRad * n++), twoPi));  }
	);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="fftChecks" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers="N((int)pow((float)2, (float)fftOrderAtStart))&#10;deltaFreq(Fs / (N - 1))&#10;m_plot{ cmp::Plot() }"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1200" initialHeight="800">
  <BACKGROUND backgroundColour="ff505050"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

