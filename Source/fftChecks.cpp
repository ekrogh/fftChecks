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
    //[/Constructor_pre]

    contButton.reset (new juce::TextButton ("contButton"));
    addAndMakeVisible (contButton.get());
    contButton->setButtonText (TRANS("Continue"));
    contButton->addListener (this);

    contButton->setBounds (437, 940, 150, 24);

    _2i2_toggleButton.reset (new juce::ToggleButton ("2i2_toggleButton"));
    addAndMakeVisible (_2i2_toggleButton.get());
    _2i2_toggleButton->setButtonText (TRANS("2 i 1"));
    _2i2_toggleButton->addListener (this);
    _2i2_toggleButton->setToggleState (true, juce::dontSendNotification);

    _2i2_toggleButton->setBounds (357, 940, 74, 24);

    maxTimeTextEditor.reset (new juce::TextEditor ("maxTimeTextEditor"));
    addAndMakeVisible (maxTimeTextEditor.get());
    maxTimeTextEditor->setTooltip (TRANS("mmax time"));
    maxTimeTextEditor->setMultiLine (false);
    maxTimeTextEditor->setReturnKeyStartsNewLine (false);
    maxTimeTextEditor->setReadOnly (false);
    maxTimeTextEditor->setScrollbarsShown (true);
    maxTimeTextEditor->setCaretVisible (true);
    maxTimeTextEditor->setPopupMenuEnabled (true);
    maxTimeTextEditor->setText (TRANS("max time"));

    maxTimeTextEditor->setBounds (18, 940, 150, 24);

    maxFreqTextEditor.reset (new juce::TextEditor ("maxFreqTextEditor"));
    addAndMakeVisible (maxFreqTextEditor.get());
    maxFreqTextEditor->setTooltip (TRANS("mac freq"));
    maxFreqTextEditor->setMultiLine (false);
    maxFreqTextEditor->setReturnKeyStartsNewLine (false);
    maxFreqTextEditor->setReadOnly (false);
    maxFreqTextEditor->setScrollbarsShown (true);
    maxFreqTextEditor->setCaretVisible (true);
    maxFreqTextEditor->setPopupMenuEnabled (true);
    maxFreqTextEditor->setText (TRANS("max freq"));

    maxFreqTextEditor->setBounds (189, 940, 150, 24);

    macFreqLabel.reset (new juce::Label ("macFreqLabel",
                                         TRANS("max freq")));
    addAndMakeVisible (macFreqLabel.get());
    macFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    macFreqLabel->setJustificationType (juce::Justification::centredLeft);
    macFreqLabel->setEditable (false, false, false);
    macFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    macFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    macFreqLabel->setBounds (189, 916, 150, 24);

    maxTimeLabel.reset (new juce::Label ("maxTimeLabel",
                                         TRANS("max time")));
    addAndMakeVisible (maxTimeLabel.get());
    maxTimeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    maxTimeLabel->setJustificationType (juce::Justification::centredLeft);
    maxTimeLabel->setEditable (false, false, false);
    maxTimeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    maxTimeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    maxTimeLabel->setBounds (18, 916, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 1000);


    //[Constructor] You can add your own custom stuff here..
	maxTimeTextEditor->setText(to_string(maxTime));
	maxFreqTextEditor->setText(to_string(maxFreq));
    //[/Constructor]
}

fftChecks::~fftChecks()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	std::free(fftbfr);
    //[/Destructor_pre]

    contButton = nullptr;
    _2i2_toggleButton = nullptr;
    maxTimeTextEditor = nullptr;
    maxFreqTextEditor = nullptr;
    macFreqLabel = nullptr;
    maxTimeLabel = nullptr;


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
    //[/UserResized]
}

void fftChecks::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == contButton.get())
    {
        //[UserButtonCode_contButton] -- add your button handler code here..
		try
		{
			if (gen)
			{
				gen();
			}

			//for (int j = 0; gen; j++)
			//	std::cout << "fib(" << j << ")=" << gen() << '\n';
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Exception: " << ex.what() << '\n';
		}
		catch (...)
		{
			std::cerr << "Unknown exception.\n";
		}
        //[/UserButtonCode_contButton]
    }
    else if (buttonThatWasClicked == _2i2_toggleButton.get())
    {
        //[UserButtonCode__2i2_toggleButton] -- add your button handler code here..
        //[/UserButtonCode__2i2_toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

fftChecks::Generator<uint64_t>
fftChecks::plotCoRoutine()
{
	doSineTime();
	co_yield 2;

	doSineFFT();
	co_yield 2;

	doFMTime();
	co_yield 4;

	doFMFFT();
	co_yield 4;

	deletePlot();

}

void fftChecks::doSine()
{
	doSineTime();
	doSineFFT();
}

void fftChecks::doFM()
{
	doFMTime();
	doFMFFT();
}

void fftChecks::doFMTime()
{
	//juce::MessageManagerLock mml;

	initNewPlot();

	// FM signal
	fillYFM();
	fillXTime();

	// Plot signal
	y_data = vector<float>(fftbfr, fftbfr + N);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plot->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plot->setTitle("FM Time domain");
	m_plot->plot({ y_data }, { x_ticksTime });
	m_plot->gridON(true, false);
}

void fftChecks::doFMFFT()
{
	// Wait for cont button to be clicked...
	//juce::MessageManagerLock mml;

	initNewPlot();

	//FFT
	fillYFM();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + (N >> 1));
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plot->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plot->setTitle("FM Freq domain");
	m_plot->plot({ y_data }, { x_ticksFFT });
	m_plot->gridON(true, false);
}

void fftChecks::doSineTime()
{
	//juce::MessageManagerLock mml;

	initNewPlot();

	fillYSin();
	fillXTime();

	y_data = vector<float>(fftbfr, fftbfr + N);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plot->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plot->setTitle("Sin Time domain");
	m_plot->plot({ y_data }, { x_ticksTime });
	m_plot->gridON(true, false);
}

void fftChecks::doSineFFT()
{
	//juce::MessageManagerLock mml;

	initNewPlot();

	fillYSin();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + (N >> 1));
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plot->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plot->setTitle("Sin Freq domain");
	m_plot->plot({ y_data }, { x_ticksFFT });
	m_plot->gridON(true, false);
}


void fftChecks::fillXFrequency()
{
	int n = 0;
	ranges::generate(x_ticksFFT, [&n, this]() { return (float)(deltaFreq * n++); });
}

void fftChecks::fillXTime()
{
	int n = 0;
	ranges::generate(x_ticksTime, [&n, this]() { return (float)(Ts * n++); });
}

void fftChecks::makeYTickLabels()
{
	auto [minY, maxY] = ranges::minmax_element(y_data);

	auto tickStep = (*maxY - *minY) / 10.0f;

	for (int i = 0; i <= 10; i++)
	{
		yTickLabels.push_back(to_string((float)i * tickStep));
	}
}

void fftChecks::fillYSin()
{
	double curPhaseCarrierSin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] = (float)sin(curPhaseCarrierSin);
		curPhaseCarrierSin =
			fmod((curPhaseCarrierSin + carrierSinFreqDeltaRad), twoPi);
	}
}

void fftChecks::fillYFM()
{
	double curSignalSin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		curSignalSin =
			sin(fmod((signalSinFreqDeltaRad * (double)i), twoPi));

		fftbfr[i] =
			(float)sin(fmod((carrierSinFreqDeltaRad * (double)i * curSignalSin), twoPi));

	}
}

void fftChecks::initNewPlot()
{
	removeMouseListener(m_plot.get());
	removeChildComponent(m_plot.get());

	m_plot = make_unique<cmp::Plot>();
	addAndMakeVisible(m_plot.get());

	resizePlotWindow();
}

void fftChecks::resizePlotWindow()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..
	auto bnds = getBounds();
	bnds.setHeight(contButton->getY());
	m_plot->setBounds(bnds);
	//[/UserResized]
}

void fftChecks::deletePlot()
{
	removeMouseListener(m_plot.get());
	removeAllChildren();

	m_plot.reset();
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
              virtualName="" explicitFocusOrder="0" pos="437 940 150 24" buttonText="Continue"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="2i2_toggleButton" id="686966a11665c450" memberName="_2i2_toggleButton"
                virtualName="" explicitFocusOrder="0" pos="357 940 74 24" buttonText="2 i 1"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTEDITOR name="maxTimeTextEditor" id="6e6d4251a2a6d380" memberName="maxTimeTextEditor"
              virtualName="" explicitFocusOrder="0" pos="18 940 150 24" tooltip="mmax time"
              initialText="max time" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="maxFreqTextEditor" id="7662909642b17a58" memberName="maxFreqTextEditor"
              virtualName="" explicitFocusOrder="0" pos="189 940 150 24" tooltip="mac freq"
              initialText="max freq" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="macFreqLabel" id="47e631ed27d9284e" memberName="macFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="189 916 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="maxTimeLabel" id="8b211e6878ea108a" memberName="maxTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="18 916 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

