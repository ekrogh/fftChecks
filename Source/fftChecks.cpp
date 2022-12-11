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

    contButton->setBounds (814, 970, 72, 24);

    _2i2_toggleButton.reset (new juce::ToggleButton ("2i2_toggleButton"));
    addAndMakeVisible (_2i2_toggleButton.get());
    _2i2_toggleButton->setButtonText (TRANS("2 i 1"));
    _2i2_toggleButton->addListener (this);
    _2i2_toggleButton->setToggleState (true, juce::dontSendNotification);

    _2i2_toggleButton->setBounds (747, 970, 59, 24);

    maxTimeTextEditor.reset (new juce::TextEditor ("maxTimeTextEditor"));
    addAndMakeVisible (maxTimeTextEditor.get());
    maxTimeTextEditor->setTooltip (TRANS("max time"));
    maxTimeTextEditor->setExplicitFocusOrder (1);
    maxTimeTextEditor->setMultiLine (false);
    maxTimeTextEditor->setReturnKeyStartsNewLine (false);
    maxTimeTextEditor->setReadOnly (false);
    maxTimeTextEditor->setScrollbarsShown (true);
    maxTimeTextEditor->setCaretVisible (true);
    maxTimeTextEditor->setPopupMenuEnabled (true);
    maxTimeTextEditor->setText (TRANS("max time"));

    maxTimeTextEditor->setBounds (56, 970, 107, 24);

    maxFreqTextEditor.reset (new juce::TextEditor ("maxFreqTextEditor"));
    addAndMakeVisible (maxFreqTextEditor.get());
    maxFreqTextEditor->setTooltip (TRANS("mac freq"));
    maxFreqTextEditor->setExplicitFocusOrder (2);
    maxFreqTextEditor->setMultiLine (false);
    maxFreqTextEditor->setReturnKeyStartsNewLine (false);
    maxFreqTextEditor->setReadOnly (false);
    maxFreqTextEditor->setScrollbarsShown (true);
    maxFreqTextEditor->setCaretVisible (true);
    maxFreqTextEditor->setPopupMenuEnabled (true);
    maxFreqTextEditor->setText (TRANS("max freq"));

    maxFreqTextEditor->setBounds (225, 970, 119, 24);

    maxFreqLabel.reset (new juce::Label ("maxFreqLabel",
                                         TRANS("max freq")));
    addAndMakeVisible (maxFreqLabel.get());
    maxFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    maxFreqLabel->setJustificationType (juce::Justification::centredLeft);
    maxFreqLabel->setEditable (false, false, false);
    maxFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    maxFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    maxFreqLabel->setBounds (169, 970, 53, 24);

    maxTimeLabel.reset (new juce::Label ("maxTimeLabel",
                                         TRANS("max time")));
    addAndMakeVisible (maxTimeLabel.get());
    maxTimeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    maxTimeLabel->setJustificationType (juce::Justification::centredLeft);
    maxTimeLabel->setEditable (false, false, false);
    maxTimeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    maxTimeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    maxTimeLabel->setBounds (0, 970, 53, 24);

    NFreqLabel.reset (new juce::Label ("NFreqLabel",
                                       TRANS("NFreq:")));
    addAndMakeVisible (NFreqLabel.get());
    NFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NFreqLabel->setJustificationType (juce::Justification::centredLeft);
    NFreqLabel->setEditable (false, false, false);
    NFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NFreqLabel->setBounds (130, 942, 51, 24);

    NFreqValueLabel.reset (new juce::Label ("NFreqValueLabel",
                                            TRANS("NFreq val\n")));
    addAndMakeVisible (NFreqValueLabel.get());
    NFreqValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NFreqValueLabel->setJustificationType (juce::Justification::centredLeft);
    NFreqValueLabel->setEditable (false, false, false);
    NFreqValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NFreqValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NFreqValueLabel->setBounds (189, 942, 80, 24);

    NTimeLabel.reset (new juce::Label ("NTimeLabel",
                                       TRANS("NTime:")));
    addAndMakeVisible (NTimeLabel.get());
    NTimeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NTimeLabel->setJustificationType (juce::Justification::centredLeft);
    NTimeLabel->setEditable (false, false, false);
    NTimeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NTimeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NTimeLabel->setBounds (0, 942, 51, 24);

    NTimeValueLabel.reset (new juce::Label ("NTimeValueLabel",
                                            TRANS("NTime val\n")));
    addAndMakeVisible (NTimeValueLabel.get());
    NTimeValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NTimeValueLabel->setJustificationType (juce::Justification::centredLeft);
    NTimeValueLabel->setEditable (false, false, false);
    NTimeValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NTimeValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NTimeValueLabel->setBounds (54, 942, 80, 24);

    defaultsTextButton.reset (new juce::TextButton ("defaultsTextButton"));
    addAndMakeVisible (defaultsTextButton.get());
    defaultsTextButton->setButtonText (TRANS("Defaults"));
    defaultsTextButton->addListener (this);

    defaultsTextButton->setBounds (814, 942, 72, 24);

    signalFreqLabel.reset (new juce::Label ("signalFreqLabel",
                                            TRANS("signal freq")));
    addAndMakeVisible (signalFreqLabel.get());
    signalFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    signalFreqLabel->setJustificationType (juce::Justification::centredLeft);
    signalFreqLabel->setEditable (false, false, false);
    signalFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    signalFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    signalFreqLabel->setBounds (349, 970, 70, 24);

    signalFreqTextEditor.reset (new juce::TextEditor ("signalFreqTextEditor"));
    addAndMakeVisible (signalFreqTextEditor.get());
    signalFreqTextEditor->setTooltip (TRANS("signal freq"));
    signalFreqTextEditor->setExplicitFocusOrder (3);
    signalFreqTextEditor->setMultiLine (false);
    signalFreqTextEditor->setReturnKeyStartsNewLine (false);
    signalFreqTextEditor->setReadOnly (false);
    signalFreqTextEditor->setScrollbarsShown (true);
    signalFreqTextEditor->setCaretVisible (true);
    signalFreqTextEditor->setPopupMenuEnabled (true);
    signalFreqTextEditor->setText (TRANS("signal freq"));

    signalFreqTextEditor->setBounds (418, 970, 102, 24);

    carrierFreqLabel.reset (new juce::Label ("carrierFreqLabel",
                                             TRANS("carrier freq")));
    addAndMakeVisible (carrierFreqLabel.get());
    carrierFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    carrierFreqLabel->setJustificationType (juce::Justification::centredLeft);
    carrierFreqLabel->setEditable (false, false, false);
    carrierFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    carrierFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    carrierFreqLabel->setBounds (533, 970, 70, 24);

    carrierFreqTextEditor.reset (new juce::TextEditor ("carrierFreqTextEditor"));
    addAndMakeVisible (carrierFreqTextEditor.get());
    carrierFreqTextEditor->setTooltip (TRANS("carrier freq"));
    carrierFreqTextEditor->setExplicitFocusOrder (4);
    carrierFreqTextEditor->setMultiLine (false);
    carrierFreqTextEditor->setReturnKeyStartsNewLine (false);
    carrierFreqTextEditor->setReadOnly (false);
    carrierFreqTextEditor->setScrollbarsShown (true);
    carrierFreqTextEditor->setCaretVisible (true);
    carrierFreqTextEditor->setPopupMenuEnabled (true);
    carrierFreqTextEditor->setText (TRANS("carrier freq"));

    carrierFreqTextEditor->setBounds (602, 970, 102, 24);

    NLabel.reset (new juce::Label ("NLabel",
                                   TRANS("N:")));
    addAndMakeVisible (NLabel.get());
    NLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NLabel->setJustificationType (juce::Justification::centredLeft);
    NLabel->setEditable (false, false, false);
    NLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NLabel->setBounds (476, 942, 31, 24);

    NValueLabel.reset (new juce::Label ("NValueLabel",
                                        TRANS("N value")));
    addAndMakeVisible (NValueLabel.get());
    NValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NValueLabel->setJustificationType (juce::Justification::centredLeft);
    NValueLabel->setEditable (false, false, false);
    NValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NValueLabel->setBounds (505, 942, 63, 24);

    TsLabel.reset (new juce::Label ("TsLabel",
                                    TRANS("Ts:")));
    addAndMakeVisible (TsLabel.get());
    TsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    TsLabel->setJustificationType (juce::Justification::centredLeft);
    TsLabel->setEditable (false, false, false);
    TsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    TsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    TsLabel->setBounds (265, 942, 31, 24);

    TsValueLabel.reset (new juce::Label ("TsValueLabel",
                                         TRANS("Ts value")));
    addAndMakeVisible (TsValueLabel.get());
    TsValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    TsValueLabel->setJustificationType (juce::Justification::centredLeft);
    TsValueLabel->setEditable (false, false, false);
    TsValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    TsValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    TsValueLabel->setBounds (294, 942, 63, 24);

    FsLabel.reset (new juce::Label ("FsLabel",
                                    TRANS("Fs:")));
    addAndMakeVisible (FsLabel.get());
    FsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FsLabel->setJustificationType (juce::Justification::centredLeft);
    FsLabel->setEditable (false, false, false);
    FsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FsLabel->setBounds (369, 942, 31, 24);

    FsValueLabel.reset (new juce::Label ("FsValueLabel",
                                         TRANS("Fs value")));
    addAndMakeVisible (FsValueLabel.get());
    FsValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FsValueLabel->setJustificationType (juce::Justification::centredLeft);
    FsValueLabel->setEditable (false, false, false);
    FsValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FsValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FsValueLabel->setBounds (398, 942, 63, 24);

    FFTOrderLabel.reset (new juce::Label ("FFTOrderLabel",
                                          TRANS("FFT Order:")));
    addAndMakeVisible (FFTOrderLabel.get());
    FFTOrderLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FFTOrderLabel->setJustificationType (juce::Justification::centredLeft);
    FFTOrderLabel->setEditable (false, false, false);
    FFTOrderLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FFTOrderLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FFTOrderLabel->setBounds (572, 942, 61, 24);

    FFTOrderValueLabel.reset (new juce::Label ("FFTOrderValueLabel",
                                               TRANS("FFT Order")));
    addAndMakeVisible (FFTOrderValueLabel.get());
    FFTOrderValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FFTOrderValueLabel->setJustificationType (juce::Justification::centredLeft);
    FFTOrderValueLabel->setEditable (false, false, false);
    FFTOrderValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FFTOrderValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FFTOrderValueLabel->setBounds (642, 942, 63, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 1000);


    //[Constructor] You can add your own custom stuff here..
    maxTimeTextEditor->addListener(this);
    maxTimeTextEditor->setSelectAllWhenFocused(true);

    maxFreqTextEditor->addListener(this);
    maxFreqTextEditor->setSelectAllWhenFocused(true);

    signalFreqTextEditor->addListener(this);
    signalFreqTextEditor->setSelectAllWhenFocused(true);

    carrierFreqTextEditor->addListener(this);
    carrierFreqTextEditor->setSelectAllWhenFocused(true);

    displayDefaults();
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
    maxFreqLabel = nullptr;
    maxTimeLabel = nullptr;
    NFreqLabel = nullptr;
    NFreqValueLabel = nullptr;
    NTimeLabel = nullptr;
    NTimeValueLabel = nullptr;
    defaultsTextButton = nullptr;
    signalFreqLabel = nullptr;
    signalFreqTextEditor = nullptr;
    carrierFreqLabel = nullptr;
    carrierFreqTextEditor = nullptr;
    NLabel = nullptr;
    NValueLabel = nullptr;
    TsLabel = nullptr;
    TsValueLabel = nullptr;
    FsLabel = nullptr;
    FsValueLabel = nullptr;
    FFTOrderLabel = nullptr;
    FFTOrderValueLabel = nullptr;


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
    else if (buttonThatWasClicked == defaultsTextButton.get())
    {
        //[UserButtonCode_defaultsTextButton] -- add your button handler code here..
        setDefaults();
        //[/UserButtonCode_defaultsTextButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void fftChecks::textEditorFocusLost(juce::TextEditor& textEditorWithReturn)
{
    handleTextEditorKeyChgs(textEditorWithReturn);
}

/** Called when the user presses the return key. */
void fftChecks::textEditorReturnKeyPressed(juce::TextEditor& textEditorWithReturn)
{
    handleTextEditorKeyChgs(textEditorWithReturn);
}

void fftChecks::handleTextEditorKeyChgs(juce::TextEditor& textEditorWithReturn)
{
	if (&textEditorWithReturn == maxTimeTextEditor.get())
	{
		maxTime = std::stod((maxTimeTextEditor->getText()).toStdString());
		updateTimeValues();
	}
	else if (&textEditorWithReturn == maxFreqTextEditor.get())
	{
		maxFreq = std::stod((maxFreqTextEditor->getText()).toStdString());
		updateFreqValues();
	}
    else if (&textEditorWithReturn == signalFreqTextEditor.get())
    {
        signalSinFreq = std::stod((signalFreqTextEditor->getText()).toStdString());
        updateSignalFreqValues();
    }
    else if (&textEditorWithReturn == carrierFreqTextEditor.get())
    {
        carrierSinFreq = std::stod((carrierFreqTextEditor->getText()).toStdString());
        updateCarrierFreqValues();
    }
}

void fftChecks::updateTimeValues()
{
	NTime = (int)(maxTime / Ts);
	x_ticksTime = vector<float>(NTime);
	NTimeValueLabel->setText(to_string(NTime), juce::NotificationType::dontSendNotification);
}

void fftChecks::updateFreqValues()
{
	NFreq = (int)(maxFreq / deltaFreq);
	x_ticksFFT = vector<float>(NFreq);
	NFreqValueLabel->setText(to_string(NFreq), juce::NotificationType::dontSendNotification);
}

void fftChecks::updateSignalFreqValues()
{
    signalSinFreqDeltaRad = signalSinFreq * twoPi * Ts;
}

void fftChecks::updateCarrierFreqValues()
{
    carrierSinFreqDeltaRad = carrierSinFreq * twoPi * Ts;
}

void fftChecks::setDefaults()
{
    maxTime = (double)N * Ts;
    NTime = (int)(maxTime / Ts);
    deltaFreq = ((double)Fs / ((double)N - (double)1));
    maxFreq = (double)(Fs >> 1);
    NFreq = (int)(maxFreq / deltaFreq);
    carrierSinFreq = (static_cast<double>(Fs) / static_cast<double>(3));
    carrierSinFreqDeltaRad =  carrierSinFreq * twoPi * Ts;
    // Signal
    signalSinFreq = 400.0f;
    signalSinFreqDeltaRad = signalSinFreq * twoPi * Ts;

    displayDefaults();
}

void fftChecks::displayDefaults()
{
    maxTimeTextEditor->setText(to_string(maxTime));
    maxFreqTextEditor->setText(to_string(maxFreq));
    signalFreqTextEditor->setText(to_string(signalSinFreq));
    carrierFreqTextEditor->setText(to_string(carrierSinFreq));
    NFreqValueLabel->setText(to_string(NFreq), juce::NotificationType::dontSendNotification);
    NTimeValueLabel->setText(to_string(NTime), juce::NotificationType::dontSendNotification);
    NValueLabel->setText(to_string(N), juce::NotificationType::dontSendNotification);
    TsValueLabel->setText(to_string(Ts), juce::NotificationType::dontSendNotification);
    FsValueLabel->setText(to_string(Fs), juce::NotificationType::dontSendNotification);
    FFTOrderValueLabel->setText(to_string(fftOrderAtStart), juce::NotificationType::dontSendNotification);
}


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
                 parentClasses="public juce::Component, public juce::TextEditor::Listener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="1200"
                 initialHeight="1000">
  <BACKGROUND backgroundColour="ff505050"/>
  <TEXTBUTTON name="contButton" id="6bbdd155c2eb5000" memberName="contButton"
              virtualName="" explicitFocusOrder="0" pos="814 970 72 24" buttonText="Continue"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="2i2_toggleButton" id="686966a11665c450" memberName="_2i2_toggleButton"
                virtualName="" explicitFocusOrder="0" pos="747 970 59 24" buttonText="2 i 1"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTEDITOR name="maxTimeTextEditor" id="6e6d4251a2a6d380" memberName="maxTimeTextEditor"
              virtualName="" explicitFocusOrder="1" pos="56 970 107 24" tooltip="max time"
              initialText="max time" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="maxFreqTextEditor" id="7662909642b17a58" memberName="maxFreqTextEditor"
              virtualName="" explicitFocusOrder="2" pos="225 970 119 24" tooltip="mac freq"
              initialText="max freq" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="maxFreqLabel" id="47e631ed27d9284e" memberName="maxFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="169 970 53 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="maxTimeLabel" id="8b211e6878ea108a" memberName="maxTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 970 53 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NFreqLabel" id="8269d5268144c2c3" memberName="NFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="130 942 51 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NFreq:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NFreqValueLabel" id="87041ef7e2c8a83f" memberName="NFreqValueLabel"
         virtualName="" explicitFocusOrder="0" pos="189 942 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NFreq val&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NTimeLabel" id="9344a5060b2bb5ab" memberName="NTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 942 51 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NTime:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NTimeValueLabel" id="108bfc80744eb74a" memberName="NTimeValueLabel"
         virtualName="" explicitFocusOrder="0" pos="54 942 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NTime val&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="defaultsTextButton" id="e1fa1deda629935b" memberName="defaultsTextButton"
              virtualName="" explicitFocusOrder="0" pos="814 942 72 24" buttonText="Defaults"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="signalFreqLabel" id="668450732d3c0888" memberName="signalFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="349 970 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="signal freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="signalFreqTextEditor" id="2fdcec6ac9445576" memberName="signalFreqTextEditor"
              virtualName="" explicitFocusOrder="3" pos="418 970 102 24" tooltip="signal freq"
              initialText="signal freq" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="carrierFreqLabel" id="c12ced105cda4573" memberName="carrierFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="533 970 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="carrier freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="carrierFreqTextEditor" id="e57cfdfa22e82311" memberName="carrierFreqTextEditor"
              virtualName="" explicitFocusOrder="4" pos="602 970 102 24" tooltip="carrier freq"
              initialText="carrier freq" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="NLabel" id="40e6abcc03fa6b5d" memberName="NLabel" virtualName=""
         explicitFocusOrder="0" pos="476 942 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="N:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NValueLabel" id="5ab3e1029e95a04e" memberName="NValueLabel"
         virtualName="" explicitFocusOrder="0" pos="505 942 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="N value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="TsLabel" id="6cc132acc14ebea9" memberName="TsLabel" virtualName=""
         explicitFocusOrder="0" pos="265 942 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ts:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="TsValueLabel" id="f7bc0c1332c0edec" memberName="TsValueLabel"
         virtualName="" explicitFocusOrder="0" pos="294 942 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ts value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FsLabel" id="82146407bdd1a63a" memberName="FsLabel" virtualName=""
         explicitFocusOrder="0" pos="369 942 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Fs:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FsValueLabel" id="bbaf72faac5c552b" memberName="FsValueLabel"
         virtualName="" explicitFocusOrder="0" pos="398 942 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Fs value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FFTOrderLabel" id="84558b9a0d701046" memberName="FFTOrderLabel"
         virtualName="" explicitFocusOrder="0" pos="572 942 61 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FFT Order:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FFTOrderValueLabel" id="9978342bb8cd07a2" memberName="FFTOrderValueLabel"
         virtualName="" explicitFocusOrder="0" pos="642 942 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FFT Order" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

