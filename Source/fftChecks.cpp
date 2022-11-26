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
{
    //[Constructor_pre] You can add your own custom stuff here..
	// Add the plot object as a child component.
	addAndMakeVisible(m_plot);
    //[/Constructor_pre]

    contButton.reset (new juce::TextButton ("contButton"));
    addAndMakeVisible (contButton.get());
    contButton->setButtonText (TRANS("Continue"));
    contButton->addListener (this);

    contButton->setBounds (448, 840, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 1000);


    //[Constructor] You can add your own custom stuff here..


	// Inits
	forwardFFT = make_unique<juce::dsp::FFT>(fftOrderAtStart);

	N = forwardFFT->getSize(); // No of points in fft
	deltaFreq = ((double)Fs / ((double)N - (double)1));
	fftbfr = (float*)std::calloc(N * 2, sizeof(float));
	x_ticks = vector<float>(N);

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
	std::free(fftbfr);
    //[/Destructor_pre]

    contButton = nullptr;


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
	auto bnds = getBounds();
	bnds.setHeight(contButton->getY());
	m_plot.setBounds(bnds);

    //[/UserResized]
}

void fftChecks::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == contButton.get())
    {
        //[UserButtonCode_contButton] -- add your button handler code here..
        weContButtonClicked.signal();
        //[/UserButtonCode_contButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
	//forwardFFT->performFrequencyOnlyForwardTransform(fftbfr);

	// Plot some values.
	m_plot.plot({ vector<float>(fftbfr, fftbfr + N) }, { x_ticks });
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
	double curPhase = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] = (float)sin(curPhase);
		curPhase = fmod((curPhase + deltaRad), twoPi);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="fftChecks" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="1200" initialHeight="1000">
  <BACKGROUND backgroundColour="ff505050"/>
  <TEXTBUTTON name="contButton" id="6bbdd155c2eb5000" memberName="contButton"
              virtualName="" explicitFocusOrder="0" pos="448 840 150 24" buttonText="Continue"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

