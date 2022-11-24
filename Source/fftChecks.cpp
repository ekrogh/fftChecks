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
fftChecks::fftChecks()
{
	//[Constructor_pre] You can add your own custom stuff here..
	//[/Constructor_pre]


	//[UserPreSize]
	//[/UserPreSize]

	setSize(1200, 800);


	//[Constructor] You can add your own custom stuff here..

	// Fill the X-axis values
	fillX();
	fillYSin();

	// Add the plot object as a child component.
	addAndMakeVisible(m_plot);

	// Plot some values.
	m_plot.plot({ y_data });
	//m_plot.plot({  y_data, x_data });

	//[/Constructor]
}

fftChecks::~fftChecks()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	//[/Destructor_pre]



	//[Destructor]. You can add your own custom destruction code here..
	//[/Destructor]
}

//==============================================================================
void fftChecks::paint(juce::Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(juce::Colour(0xff505050));

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
void fftChecks::fillX()
{
	int n = 0;
	std::ranges::generate(x_data, [&n, this]() { return deltaFreq * n++;  });
}

void fftChecks::fillYSin()
{
	constexpr double sinFreq = (Fs / 200);
	constexpr double deltaRad = sinFreq * twoPi * Ts;
	int n = 0;
	std::ranges::generate
	(
		y_data
		, [&n, &deltaRad, this] ()
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
				 parentClasses="public juce::Component" constructorParams="" variableInitialisers="m_plot{ cmp::Plot() }"
				 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
				 fixedSize="0" initialWidth="1200" initialHeight="800">
  <BACKGROUND backgroundColour="ff505050"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

