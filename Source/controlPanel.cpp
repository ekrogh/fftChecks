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
#include "fftChecks.h"
//[/Headers]

#include "controlPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
controlPanel::controlPanel (shared_ptr<fftChecks> pFFTChks)
    : pFFTChecks(pFFTChks)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    maxTimeTextEditor.reset (new juce::TextEditor ("maxTimeTextEditor"));
    addAndMakeVisible (maxTimeTextEditor.get());
    maxTimeTextEditor->setTooltip (TRANS("max time"));
    maxTimeTextEditor->setExplicitFocusOrder (3);
    maxTimeTextEditor->setMultiLine (false);
    maxTimeTextEditor->setReturnKeyStartsNewLine (false);
    maxTimeTextEditor->setReadOnly (false);
    maxTimeTextEditor->setScrollbarsShown (true);
    maxTimeTextEditor->setCaretVisible (true);
    maxTimeTextEditor->setPopupMenuEnabled (true);
    maxTimeTextEditor->setText (TRANS("max time"));

    maxTimeTextEditor->setBounds (72, 94, 95, 24);

    maxFreqTextEditor.reset (new juce::TextEditor ("maxFreqTextEditor"));
    addAndMakeVisible (maxFreqTextEditor.get());
    maxFreqTextEditor->setTooltip (TRANS("mac freq"));
    maxFreqTextEditor->setExplicitFocusOrder (4);
    maxFreqTextEditor->setMultiLine (false);
    maxFreqTextEditor->setReturnKeyStartsNewLine (false);
    maxFreqTextEditor->setReadOnly (false);
    maxFreqTextEditor->setScrollbarsShown (true);
    maxFreqTextEditor->setCaretVisible (true);
    maxFreqTextEditor->setPopupMenuEnabled (true);
    maxFreqTextEditor->setText (TRANS("max freq"));

    maxFreqTextEditor->setBounds (244, 94, 95, 24);

    maxFreqLabel.reset (new juce::Label ("maxFreqLabel",
                                         TRANS("max freq")));
    addAndMakeVisible (maxFreqLabel.get());
    maxFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    maxFreqLabel->setJustificationType (juce::Justification::centredLeft);
    maxFreqLabel->setEditable (false, false, false);
    maxFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    maxFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    maxFreqLabel->setBounds (175, 94, 53, 24);

    maxTimeLabel.reset (new juce::Label ("maxTimeLabel",
                                         TRANS("max time")));
    addAndMakeVisible (maxTimeLabel.get());
    maxTimeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    maxTimeLabel->setJustificationType (juce::Justification::centredLeft);
    maxTimeLabel->setEditable (false, false, false);
    maxTimeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    maxTimeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    maxTimeLabel->setBounds (0, 94, 70, 24);

    NFreqLabel.reset (new juce::Label ("NFreqLabel",
                                       TRANS("NFreq")));
    addAndMakeVisible (NFreqLabel.get());
    NFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NFreqLabel->setJustificationType (juce::Justification::centredLeft);
    NFreqLabel->setEditable (false, false, false);
    NFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NFreqLabel->setBounds (130, 24, 80, 24);

    NFreqValueLabel.reset (new juce::Label ("NFreqValueLabel",
                                            TRANS("NFreq val\n")));
    addAndMakeVisible (NFreqValueLabel.get());
    NFreqValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NFreqValueLabel->setJustificationType (juce::Justification::centredLeft);
    NFreqValueLabel->setEditable (false, false, false);
    NFreqValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NFreqValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NFreqValueLabel->setBounds (189, 24, 80, 24);

    NTimeLabel.reset (new juce::Label ("NTimeLabel",
                                       TRANS("NTime")));
    addAndMakeVisible (NTimeLabel.get());
    NTimeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NTimeLabel->setJustificationType (juce::Justification::centredLeft);
    NTimeLabel->setEditable (false, false, false);
    NTimeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NTimeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NTimeLabel->setBounds (0, 24, 51, 24);

    NTimeValueLabel.reset (new juce::Label ("NTimeValueLabel",
                                            TRANS("NTime val\n")));
    addAndMakeVisible (NTimeValueLabel.get());
    NTimeValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NTimeValueLabel->setJustificationType (juce::Justification::centredLeft);
    NTimeValueLabel->setEditable (false, false, false);
    NTimeValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NTimeValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NTimeValueLabel->setBounds (54, 24, 80, 24);

    signalFreqLabel.reset (new juce::Label ("signalFreqLabel",
                                            TRANS("signal freq")));
    addAndMakeVisible (signalFreqLabel.get());
    signalFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    signalFreqLabel->setJustificationType (juce::Justification::centredLeft);
    signalFreqLabel->setEditable (false, false, false);
    signalFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    signalFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    signalFreqLabel->setBounds (0, 125, 70, 24);

    signalFreqTextEditor.reset (new juce::TextEditor ("signalFreqTextEditor"));
    addAndMakeVisible (signalFreqTextEditor.get());
    signalFreqTextEditor->setTooltip (TRANS("signal freq"));
    signalFreqTextEditor->setExplicitFocusOrder (5);
    signalFreqTextEditor->setMultiLine (false);
    signalFreqTextEditor->setReturnKeyStartsNewLine (false);
    signalFreqTextEditor->setReadOnly (false);
    signalFreqTextEditor->setScrollbarsShown (true);
    signalFreqTextEditor->setCaretVisible (true);
    signalFreqTextEditor->setPopupMenuEnabled (true);
    signalFreqTextEditor->setText (TRANS("signal freq"));

    signalFreqTextEditor->setBounds (72, 124, 95, 24);

    carrierFreqLabel.reset (new juce::Label ("carrierFreqLabel",
                                             TRANS("carrier freq")));
    addAndMakeVisible (carrierFreqLabel.get());
    carrierFreqLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    carrierFreqLabel->setJustificationType (juce::Justification::centredLeft);
    carrierFreqLabel->setEditable (false, false, false);
    carrierFreqLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    carrierFreqLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    carrierFreqLabel->setBounds (175, 125, 70, 24);

    carrierFreqTextEditor.reset (new juce::TextEditor ("carrierFreqTextEditor"));
    addAndMakeVisible (carrierFreqTextEditor.get());
    carrierFreqTextEditor->setTooltip (TRANS("carrier freq"));
    carrierFreqTextEditor->setExplicitFocusOrder (6);
    carrierFreqTextEditor->setMultiLine (false);
    carrierFreqTextEditor->setReturnKeyStartsNewLine (false);
    carrierFreqTextEditor->setReadOnly (false);
    carrierFreqTextEditor->setScrollbarsShown (true);
    carrierFreqTextEditor->setCaretVisible (true);
    carrierFreqTextEditor->setPopupMenuEnabled (true);
    carrierFreqTextEditor->setText (TRANS("carrier freq"));

    carrierFreqTextEditor->setBounds (244, 125, 95, 24);

    NLabel.reset (new juce::Label ("NLabel",
                                   TRANS("N")));
    addAndMakeVisible (NLabel.get());
    NLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NLabel->setJustificationType (juce::Justification::centredLeft);
    NLabel->setEditable (false, false, false);
    NLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NLabel->setBounds (0, 0, 31, 24);

    NValueLabel.reset (new juce::Label ("NValueLabel",
                                        TRANS("N value")));
    addAndMakeVisible (NValueLabel.get());
    NValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    NValueLabel->setJustificationType (juce::Justification::centredLeft);
    NValueLabel->setEditable (false, false, false);
    NValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    NValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    NValueLabel->setBounds (54, 0, 80, 24);

    TsLabel.reset (new juce::Label ("TsLabel",
                                    TRANS("Ts")));
    addAndMakeVisible (TsLabel.get());
    TsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    TsLabel->setJustificationType (juce::Justification::centredLeft);
    TsLabel->setEditable (false, false, false);
    TsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    TsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    TsLabel->setBounds (130, 0, 80, 24);

    TsValueLabel.reset (new juce::Label ("TsValueLabel",
                                         TRANS("Ts value")));
    addAndMakeVisible (TsValueLabel.get());
    TsValueLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    TsValueLabel->setJustificationType (juce::Justification::centredLeft);
    TsValueLabel->setEditable (false, false, false);
    TsValueLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    TsValueLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    TsValueLabel->setBounds (189, 0, 63, 24);

    FsLabel.reset (new juce::Label ("FsLabel",
                                    TRANS("Fs")));
    addAndMakeVisible (FsLabel.get());
    FsLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FsLabel->setJustificationType (juce::Justification::centredLeft);
    FsLabel->setEditable (false, false, false);
    FsLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FsLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FsLabel->setBounds (175, 65, 31, 24);

    FFTOrderLabel.reset (new juce::Label ("FFTOrderLabel",
                                          TRANS("FFT Order")));
    addAndMakeVisible (FFTOrderLabel.get());
    FFTOrderLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FFTOrderLabel->setJustificationType (juce::Justification::centredLeft);
    FFTOrderLabel->setEditable (false, false, false);
    FFTOrderLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FFTOrderLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FFTOrderLabel->setBounds (0, 65, 70, 24);

    fftOrderTextEditor.reset (new juce::TextEditor ("fftOrderTextEditor"));
    addAndMakeVisible (fftOrderTextEditor.get());
    fftOrderTextEditor->setExplicitFocusOrder (1);
    fftOrderTextEditor->setMultiLine (false);
    fftOrderTextEditor->setReturnKeyStartsNewLine (false);
    fftOrderTextEditor->setReadOnly (false);
    fftOrderTextEditor->setScrollbarsShown (true);
    fftOrderTextEditor->setCaretVisible (true);
    fftOrderTextEditor->setPopupMenuEnabled (true);
    fftOrderTextEditor->setText (TRANS("fft order"));

    fftOrderTextEditor->setBounds (72, 65, 95, 24);

    FsTextEditor.reset (new juce::TextEditor ("FsTextEditor"));
    addAndMakeVisible (FsTextEditor.get());
    FsTextEditor->setExplicitFocusOrder (2);
    FsTextEditor->setMultiLine (false);
    FsTextEditor->setReturnKeyStartsNewLine (false);
    FsTextEditor->setReadOnly (false);
    FsTextEditor->setScrollbarsShown (true);
    FsTextEditor->setCaretVisible (true);
    FsTextEditor->setPopupMenuEnabled (true);
    FsTextEditor->setText (TRANS("Fs"));

    FsTextEditor->setBounds (244, 65, 95, 24);

    contButton.reset (new juce::TextButton ("contButton"));
    addAndMakeVisible (contButton.get());
    contButton->setExplicitFocusOrder (7);
    contButton->setButtonText (TRANS("Continue"));
    contButton->addListener (this);

    contButton->setBounds (72, 394, 95, 24);

    _2i2_toggleButton.reset (new juce::ToggleButton ("2i2_toggleButton"));
    addAndMakeVisible (_2i2_toggleButton.get());
    _2i2_toggleButton->setButtonText (TRANS("2 i 1"));
    _2i2_toggleButton->addListener (this);
    _2i2_toggleButton->setToggleState (true, juce::dontSendNotification);

    _2i2_toggleButton->setBounds (0, 392, 59, 24);

    defaultsTextButton.reset (new juce::TextButton ("defaultsTextButton"));
    addAndMakeVisible (defaultsTextButton.get());
    defaultsTextButton->setButtonText (TRANS("Defaults"));
    defaultsTextButton->addListener (this);

    defaultsTextButton->setBounds (244, 394, 95, 24);

    sourceTypeComboBox.reset (new juce::ComboBox ("sourceTypeComboBox"));
    addAndMakeVisible (sourceTypeComboBox.get());
    sourceTypeComboBox->setEditableText (false);
    sourceTypeComboBox->setJustificationType (juce::Justification::centredLeft);
    sourceTypeComboBox->setTextWhenNothingSelected (juce::String());
    sourceTypeComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    sourceTypeComboBox->addListener (this);

    sourceTypeComboBox->setBounds (69, 191, 95, 24);

    sourceTypeLabel.reset (new juce::Label ("sourceTypeLabel",
                                            TRANS("signal type")));
    addAndMakeVisible (sourceTypeLabel.get());
    sourceTypeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sourceTypeLabel->setJustificationType (juce::Justification::centredLeft);
    sourceTypeLabel->setEditable (false, false, false);
    sourceTypeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sourceTypeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sourceTypeLabel->setBounds (0, 191, 70, 24);

    modulationIndxLabel.reset (new juce::Label ("modulationIndxLabel",
                                                TRANS("mod. idx.")));
    addAndMakeVisible (modulationIndxLabel.get());
    modulationIndxLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    modulationIndxLabel->setJustificationType (juce::Justification::centredLeft);
    modulationIndxLabel->setEditable (false, false, false);
    modulationIndxLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    modulationIndxLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    modulationIndxLabel->setBounds (0, 155, 70, 24);

    modulationIndexTextEditor.reset (new juce::TextEditor ("modulationIndexTextEditor"));
    addAndMakeVisible (modulationIndexTextEditor.get());
    modulationIndexTextEditor->setTooltip (TRANS("modulation index"));
    modulationIndexTextEditor->setExplicitFocusOrder (5);
    modulationIndexTextEditor->setMultiLine (false);
    modulationIndexTextEditor->setReturnKeyStartsNewLine (false);
    modulationIndexTextEditor->setReadOnly (false);
    modulationIndexTextEditor->setScrollbarsShown (true);
    modulationIndexTextEditor->setCaretVisible (true);
    modulationIndexTextEditor->setPopupMenuEnabled (true);
    modulationIndexTextEditor->setText (TRANS("modulation index"));

    modulationIndexTextEditor->setBounds (72, 154, 95, 24);

    carrierAmplitudeLabel.reset (new juce::Label ("carrierAmplitudeLabel",
                                                  TRANS("carrier Amplt")));
    addAndMakeVisible (carrierAmplitudeLabel.get());
    carrierAmplitudeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    carrierAmplitudeLabel->setJustificationType (juce::Justification::centredLeft);
    carrierAmplitudeLabel->setEditable (false, false, false);
    carrierAmplitudeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    carrierAmplitudeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    carrierAmplitudeLabel->setBounds (175, 154, 70, 24);

    carrierAmplitudeTextEditor.reset (new juce::TextEditor ("carrierAmplitudeTextEditor"));
    addAndMakeVisible (carrierAmplitudeTextEditor.get());
    carrierAmplitudeTextEditor->setTooltip (TRANS("carrier amplt"));
    carrierAmplitudeTextEditor->setExplicitFocusOrder (6);
    carrierAmplitudeTextEditor->setMultiLine (false);
    carrierAmplitudeTextEditor->setReturnKeyStartsNewLine (false);
    carrierAmplitudeTextEditor->setReadOnly (false);
    carrierAmplitudeTextEditor->setScrollbarsShown (true);
    carrierAmplitudeTextEditor->setCaretVisible (true);
    carrierAmplitudeTextEditor->setPopupMenuEnabled (true);
    carrierAmplitudeTextEditor->setText (TRANS("carrier amplitude"));

    carrierAmplitudeTextEditor->setBounds (244, 154, 95, 24);

    signalInCombinedPlotToggleButton.reset (new juce::ToggleButton ("signalInCombinedPlotToggleButton"));
    addAndMakeVisible (signalInCombinedPlotToggleButton.get());
    signalInCombinedPlotToggleButton->setTooltip (TRANS("signal in combined plot"));
    signalInCombinedPlotToggleButton->setButtonText (juce::String());
    signalInCombinedPlotToggleButton->addListener (this);

    signalInCombinedPlotToggleButton->setBounds (77, 256, 32, 24);

    toPlotLabel.reset (new juce::Label ("toPlotLabel",
                                        TRANS("plot:")));
    addAndMakeVisible (toPlotLabel.get());
    toPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    toPlotLabel->setJustificationType (juce::Justification::centredLeft);
    toPlotLabel->setEditable (false, false, false);
    toPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    toPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    toPlotLabel->setBounds (0, 228, 39, 24);

    inCombinedPlotLabel.reset (new juce::Label ("inCombinedPlotLabel",
                                                TRANS("in combined plot")));
    addAndMakeVisible (inCombinedPlotLabel.get());
    inCombinedPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    inCombinedPlotLabel->setJustificationType (juce::Justification::centredLeft);
    inCombinedPlotLabel->setEditable (false, false, false);
    inCombinedPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    inCombinedPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    inCombinedPlotLabel->setBounds (77, 228, 87, 24);

    carrierInCombinedPlotToggleButton.reset (new juce::ToggleButton ("carrierInCombinedPlotToggleButton"));
    addAndMakeVisible (carrierInCombinedPlotToggleButton.get());
    carrierInCombinedPlotToggleButton->setTooltip (TRANS("carrier in combined plot"));
    carrierInCombinedPlotToggleButton->setButtonText (juce::String());
    carrierInCombinedPlotToggleButton->addListener (this);

    carrierInCombinedPlotToggleButton->setBounds (77, 285, 32, 24);

    modulatedInCombinedPlotToggleButton.reset (new juce::ToggleButton ("modulatedInCombinedPlotToggleButton"));
    addAndMakeVisible (modulatedInCombinedPlotToggleButton.get());
    modulatedInCombinedPlotToggleButton->setTooltip (TRANS("mpdulated in combined plot"));
    modulatedInCombinedPlotToggleButton->setButtonText (juce::String());
    modulatedInCombinedPlotToggleButton->addListener (this);

    modulatedInCombinedPlotToggleButton->setBounds (77, 315, 32, 24);

    signalInIndividualPlotToggleButton.reset (new juce::ToggleButton ("signalInIndividualPlotToggleButton"));
    addAndMakeVisible (signalInIndividualPlotToggleButton.get());
    signalInIndividualPlotToggleButton->setTooltip (TRANS("signal in same plot"));
    signalInIndividualPlotToggleButton->setButtonText (juce::String());
    signalInIndividualPlotToggleButton->addListener (this);

    signalInIndividualPlotToggleButton->setBounds (173, 255, 32, 24);

    individualPlotLabel.reset (new juce::Label ("individualPlotLabel",
                                                TRANS("individual plot")));
    addAndMakeVisible (individualPlotLabel.get());
    individualPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    individualPlotLabel->setJustificationType (juce::Justification::centredLeft);
    individualPlotLabel->setEditable (false, false, false);
    individualPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    individualPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    individualPlotLabel->setBounds (173, 227, 87, 24);

    carrierInIndividualPlotToggleButton.reset (new juce::ToggleButton ("carrierInIndividualPlotToggleButton"));
    addAndMakeVisible (carrierInIndividualPlotToggleButton.get());
    carrierInIndividualPlotToggleButton->setTooltip (TRANS("carrier in individual plot"));
    carrierInIndividualPlotToggleButton->setButtonText (juce::String());
    carrierInIndividualPlotToggleButton->addListener (this);

    carrierInIndividualPlotToggleButton->setBounds (173, 284, 32, 24);

    modulatedInIndividualPlotToggleButton.reset (new juce::ToggleButton ("modulatedInIndividualPlotToggleButton"));
    addAndMakeVisible (modulatedInIndividualPlotToggleButton.get());
    modulatedInIndividualPlotToggleButton->setTooltip (TRANS("mpdulated in individual plot"));
    modulatedInIndividualPlotToggleButton->setButtonText (juce::String());
    modulatedInIndividualPlotToggleButton->addListener (this);

    modulatedInIndividualPlotToggleButton->setBounds (173, 314, 32, 24);

    FFTInIndividualPlotToggleButton.reset (new juce::ToggleButton ("FFTInIndividualPlotToggleButton"));
    addAndMakeVisible (FFTInIndividualPlotToggleButton.get());
    FFTInIndividualPlotToggleButton->setTooltip (TRANS("FFT in individual plot"));
    FFTInIndividualPlotToggleButton->setButtonText (juce::String());
    FFTInIndividualPlotToggleButton->addListener (this);

    FFTInIndividualPlotToggleButton->setBounds (173, 344, 32, 24);

    signalPlotLabel.reset (new juce::Label ("signalPlotLabel",
                                            TRANS("signal")));
    addAndMakeVisible (signalPlotLabel.get());
    signalPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    signalPlotLabel->setJustificationType (juce::Justification::centredLeft);
    signalPlotLabel->setEditable (false, false, false);
    signalPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    signalPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    signalPlotLabel->setBounds (0, 255, 72, 24);

    carrierPlotLabel.reset (new juce::Label ("carrierPlotLabel",
                                             TRANS("carrier")));
    addAndMakeVisible (carrierPlotLabel.get());
    carrierPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    carrierPlotLabel->setJustificationType (juce::Justification::centredLeft);
    carrierPlotLabel->setEditable (false, false, false);
    carrierPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    carrierPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    carrierPlotLabel->setBounds (0, 285, 72, 24);

    modulatedPlotLabel.reset (new juce::Label ("modulatedPlotLabel",
                                               TRANS("modulated")));
    addAndMakeVisible (modulatedPlotLabel.get());
    modulatedPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    modulatedPlotLabel->setJustificationType (juce::Justification::centredLeft);
    modulatedPlotLabel->setEditable (false, false, false);
    modulatedPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    modulatedPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    modulatedPlotLabel->setBounds (0, 315, 72, 24);

    FFTPlotLabel.reset (new juce::Label ("FFTPlotLabel",
                                         TRANS("FFT")));
    addAndMakeVisible (FFTPlotLabel.get());
    FFTPlotLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    FFTPlotLabel->setJustificationType (juce::Justification::centredLeft);
    FFTPlotLabel->setEditable (false, false, false);
    FFTPlotLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    FFTPlotLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    FFTPlotLabel->setBounds (0, 345, 72, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (350, 440);


    //[Constructor] You can add your own custom stuff here..
	maxTimeTextEditor->addListener(this);
	maxTimeTextEditor->setSelectAllWhenFocused(true);

	maxFreqTextEditor->addListener(this);
	maxFreqTextEditor->setSelectAllWhenFocused(true);

	signalFreqTextEditor->addListener(this);
	signalFreqTextEditor->setSelectAllWhenFocused(true);

	carrierFreqTextEditor->addListener(this);
	carrierFreqTextEditor->setSelectAllWhenFocused(true);

	fftOrderTextEditor->addListener(this);
	fftOrderTextEditor->setSelectAllWhenFocused(true);

	FsTextEditor->addListener(this);
	FsTextEditor->setSelectAllWhenFocused(true);

	modulationIndexTextEditor->addListener(this);
	modulationIndexTextEditor->setSelectAllWhenFocused(true);

	carrierAmplitudeTextEditor->addListener(this);
	carrierAmplitudeTextEditor->setSelectAllWhenFocused(true);

	sourceTypeComboBox->addItem("sin", sinSource);
	sourceTypeComboBox->addItem("FM", FMSource);
	sourceTypeComboBox->addItem("AM", AMSource);
	sourceTypeComboBox->setSelectedId(sinSource);
	pFFTChecks->set_sourceType(sourceTypeComboBox->getSelectedId());


	pFFTChecks->set_signal_in_combined_plot(signalInCombinedPlotToggleButton->getToggleState());
	pFFTChecks->set_signal_in_individual_plot(signalInIndividualPlotToggleButton->getToggleState());

	pFFTChecks->set_carrier_in_combined_plot(carrierInCombinedPlotToggleButton->getToggleState());
	pFFTChecks->set_carrier_in_individual_plot(carrierInIndividualPlotToggleButton->getToggleState());

	pFFTChecks->set_modulated_in_combined_plot(modulatedInCombinedPlotToggleButton->getToggleState());
	pFFTChecks->set_modulated_in_individual_plot(modulatedInIndividualPlotToggleButton->getToggleState());
	pFFTChecks->set_FFT_in_combined_plot(false);
	pFFTChecks->set_FFT_in_individual_plot(FFTInIndividualPlotToggleButton->getToggleState());


	displayAll();

	toFront(true);
    //[/Constructor]
}

controlPanel::~controlPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    maxTimeTextEditor = nullptr;
    maxFreqTextEditor = nullptr;
    maxFreqLabel = nullptr;
    maxTimeLabel = nullptr;
    NFreqLabel = nullptr;
    NFreqValueLabel = nullptr;
    NTimeLabel = nullptr;
    NTimeValueLabel = nullptr;
    signalFreqLabel = nullptr;
    signalFreqTextEditor = nullptr;
    carrierFreqLabel = nullptr;
    carrierFreqTextEditor = nullptr;
    NLabel = nullptr;
    NValueLabel = nullptr;
    TsLabel = nullptr;
    TsValueLabel = nullptr;
    FsLabel = nullptr;
    FFTOrderLabel = nullptr;
    fftOrderTextEditor = nullptr;
    FsTextEditor = nullptr;
    contButton = nullptr;
    _2i2_toggleButton = nullptr;
    defaultsTextButton = nullptr;
    sourceTypeComboBox = nullptr;
    sourceTypeLabel = nullptr;
    modulationIndxLabel = nullptr;
    modulationIndexTextEditor = nullptr;
    carrierAmplitudeLabel = nullptr;
    carrierAmplitudeTextEditor = nullptr;
    signalInCombinedPlotToggleButton = nullptr;
    toPlotLabel = nullptr;
    inCombinedPlotLabel = nullptr;
    carrierInCombinedPlotToggleButton = nullptr;
    modulatedInCombinedPlotToggleButton = nullptr;
    signalInIndividualPlotToggleButton = nullptr;
    individualPlotLabel = nullptr;
    carrierInIndividualPlotToggleButton = nullptr;
    modulatedInIndividualPlotToggleButton = nullptr;
    FFTInIndividualPlotToggleButton = nullptr;
    signalPlotLabel = nullptr;
    carrierPlotLabel = nullptr;
    modulatedPlotLabel = nullptr;
    FFTPlotLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void controlPanel::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void controlPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void controlPanel::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == contButton.get())
    {
        //[UserButtonCode_contButton] -- add your button handler code here..
		doContButtonPresse();
        //[/UserButtonCode_contButton]
    }
    else if (buttonThatWasClicked == _2i2_toggleButton.get())
    {
        //[UserButtonCode__2i2_toggleButton] -- add your button handler code here..
		pFFTChecks->set_allIn1ToggleButtonToggleState
		(
			_2i2_toggleButton->getToggleState()
		);
        //[/UserButtonCode__2i2_toggleButton]
    }
    else if (buttonThatWasClicked == defaultsTextButton.get())
    {
        //[UserButtonCode_defaultsTextButton] -- add your button handler code here..
		setDefaults();
        //[/UserButtonCode_defaultsTextButton]
    }
    else if (buttonThatWasClicked == signalInCombinedPlotToggleButton.get())
    {
        //[UserButtonCode_signalInCombinedPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_signal_in_combined_plot(signalInCombinedPlotToggleButton->getToggleState());
        //[/UserButtonCode_signalInCombinedPlotToggleButton]
    }
    else if (buttonThatWasClicked == carrierInCombinedPlotToggleButton.get())
    {
        //[UserButtonCode_carrierInCombinedPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_carrier_in_combined_plot(carrierInCombinedPlotToggleButton->getToggleState());
        //[/UserButtonCode_carrierInCombinedPlotToggleButton]
    }
    else if (buttonThatWasClicked == modulatedInCombinedPlotToggleButton.get())
    {
        //[UserButtonCode_modulatedInCombinedPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_modulated_in_combined_plot(modulatedInCombinedPlotToggleButton->getToggleState());
        //[/UserButtonCode_modulatedInCombinedPlotToggleButton]
    }
    else if (buttonThatWasClicked == signalInIndividualPlotToggleButton.get())
    {
        //[UserButtonCode_signalInIndividualPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_signal_in_individual_plot(signalInIndividualPlotToggleButton->getToggleState());
        //[/UserButtonCode_signalInIndividualPlotToggleButton]
    }
    else if (buttonThatWasClicked == carrierInIndividualPlotToggleButton.get())
    {
        //[UserButtonCode_carrierInIndividualPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_carrier_in_individual_plot(carrierInIndividualPlotToggleButton->getToggleState());
        //[/UserButtonCode_carrierInIndividualPlotToggleButton]
    }
    else if (buttonThatWasClicked == modulatedInIndividualPlotToggleButton.get())
    {
        //[UserButtonCode_modulatedInIndividualPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_modulated_in_individual_plot(modulatedInIndividualPlotToggleButton->getToggleState());
        //[/UserButtonCode_modulatedInIndividualPlotToggleButton]
    }
    else if (buttonThatWasClicked == FFTInIndividualPlotToggleButton.get())
    {
        //[UserButtonCode_FFTInIndividualPlotToggleButton] -- add your button handler code here..
		pFFTChecks->set_FFT_in_individual_plot(FFTInIndividualPlotToggleButton->getToggleState());
        //[/UserButtonCode_FFTInIndividualPlotToggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void controlPanel::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == sourceTypeComboBox.get())
    {
        //[UserComboBoxCode_sourceTypeComboBox] -- add your combo box handling code here..
		pFFTChecks->set_sourceType(sourceTypeComboBox->getSelectedId());
        //[/UserComboBoxCode_sourceTypeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void controlPanel::textEditorFocusLost(juce::TextEditor& textEditorWithReturn)
{
	handleTextEditorKeyChgs(textEditorWithReturn);
}

/** Called when the user presses the return key. */
void controlPanel::textEditorReturnKeyPressed(juce::TextEditor& textEditorWithReturn)
{
	handleTextEditorKeyChgs(textEditorWithReturn);
}

void controlPanel::handleTextEditorKeyChgs(juce::TextEditor& textEditorWithReturn)
{
	if (&textEditorWithReturn == maxTimeTextEditor.get())
	{
		pFFTChecks->set_maxTime(std::stod((maxTimeTextEditor->getText()).toStdString()));
		updateTimeValues();
	}
	else if (&textEditorWithReturn == maxFreqTextEditor.get())
	{
		pFFTChecks->set_maxFreq(std::stod((maxFreqTextEditor->getText()).toStdString()));
		updateFreqValues();
	}
	else if (&textEditorWithReturn == signalFreqTextEditor.get())
	{
		pFFTChecks->set_signalSinFreq(std::stod((signalFreqTextEditor->getText()).toStdString()));
		updateSignalFreqValues();
	}
	else if (&textEditorWithReturn == carrierFreqTextEditor.get())
	{
		pFFTChecks->set_carrierSinFreq(std::stod((carrierFreqTextEditor->getText()).toStdString()));
		updateCarrierFreqValues();
	}
	else if (&textEditorWithReturn == carrierAmplitudeTextEditor.get())
	{
		pFFTChecks->set_carrierAmplitude
		(
			std::stod((carrierAmplitudeTextEditor->getText()).toStdString())
		);
	}
	else if (&textEditorWithReturn == modulationIndexTextEditor.get())
	{
		pFFTChecks->set_modulationIndex
		(
			std::stod((modulationIndexTextEditor->getText()).toStdString())
		);
	}
	else if (&textEditorWithReturn == fftOrderTextEditor.get())
	{
		pFFTChecks->set_fftOrder(std::stoi((fftOrderTextEditor->getText()).toStdString()));
		updatefftOrderValues();
	}
	else if (&textEditorWithReturn == FsTextEditor.get())
	{
		pFFTChecks->set_Fs(std::stoi((FsTextEditor->getText()).toStdString()));
		updateFsValues();
	}
}

void controlPanel::updatefftOrderValues()
{
	pFFTChecks->updatefftOrderValues();

	displayAll();
}

void controlPanel::updateFsValues()
{
	pFFTChecks->updateFsValues();

	displayAll();
}

void controlPanel::updateTimeValues()
{
	pFFTChecks->set_NTime((int)(pFFTChecks->get_maxTime() / pFFTChecks->get_Ts()));
	NTimeValueLabel->setText
	(
		to_string(pFFTChecks->get_NTime())
		, juce::NotificationType::dontSendNotification
	);
}

void controlPanel::updateFreqValues()
{
	pFFTChecks->set_NFreq((int)(pFFTChecks->get_maxFreq() / pFFTChecks->get_deltaFreq()));
	NFreqValueLabel->setText
	(
		to_string(pFFTChecks->get_NFreq())
		, juce::NotificationType::dontSendNotification
	);
}

void controlPanel::updateSignalFreqValues()
{
	pFFTChecks->set_signalSinFreqDeltaRad
	(
		pFFTChecks->get_signalSinFreq()
		* pFFTChecks->get_twoPi()
		* pFFTChecks->get_Ts()
	);
}

void controlPanel::updateCarrierFreqValues()
{
	pFFTChecks->set_carrierSinFreqDeltaRad
	(
		pFFTChecks->get_carrierSinFreq()
		* pFFTChecks->get_twoPi()
		* pFFTChecks->get_Ts()
	);
}

void controlPanel::setDefaults()
{
	pFFTChecks->set_fftOrder(11);
	updatefftOrderValues();

	pFFTChecks->set_Fs(48000);
	updateFsValues();

	pFFTChecks->set_maxTime
	(
		(double)(pFFTChecks->get_N())
		* pFFTChecks->get_Ts()
	);

	pFFTChecks->set_NTime
	(
		(int)((pFFTChecks->get_maxTime()) / pFFTChecks->get_Ts())
	);

	pFFTChecks->set_deltaFreq
	(
		(double)(pFFTChecks->get_Fs()) / ((double)(pFFTChecks->get_N()) - (double)1)
	);

	pFFTChecks->set_maxFreq
	(
		(double)((int)(pFFTChecks->get_Fs()) >> 1)
	);

	pFFTChecks->set_NFreq
	(
		(int)(pFFTChecks->get_maxFreq() / pFFTChecks->get_deltaFreq())
	);

	pFFTChecks->set_carrierSinFreq
	(
		2000.0f
	);
	updateCarrierFreqValues();

	// Signal
	pFFTChecks->set_signalSinFreq(400.0f);
	updateSignalFreqValues();

	// In plots
	pFFTChecks->set_signal_in_combined_plot(false);
	pFFTChecks->set_signal_in_individual_plot(false);

	pFFTChecks->set_carrier_in_combined_plot(false);
	pFFTChecks->set_carrier_in_individual_plot(false);

	pFFTChecks->set_modulated_in_combined_plot(false);
	pFFTChecks->set_modulated_in_individual_plot(false);

	pFFTChecks->set_FFT_in_combined_plot(false);
	pFFTChecks->set_FFT_in_individual_plot(false);

	displayAll();
}

void controlPanel::displayAll()
{

	maxTimeTextEditor->setText(to_string(pFFTChecks->get_maxTime()), false);
	maxFreqTextEditor->setText(to_string(pFFTChecks->get_maxFreq()), false);
	signalFreqTextEditor->setText(to_string(pFFTChecks->get_signalSinFreq()), false);
	carrierFreqTextEditor->setText(to_string(pFFTChecks->get_carrierSinFreq()), false);
	NFreqValueLabel->setText(to_string(pFFTChecks->get_NFreq()), juce::NotificationType::dontSendNotification);
	NTimeValueLabel->setText(to_string(pFFTChecks->get_NTime()), juce::NotificationType::dontSendNotification);
	NValueLabel->setText(to_string(pFFTChecks->get_N()), juce::NotificationType::dontSendNotification);
	TsValueLabel->setText(to_string(pFFTChecks->get_Ts()), juce::NotificationType::dontSendNotification);
	FsTextEditor->setText(to_string(pFFTChecks->get_Fs()), false);
	fftOrderTextEditor->setText(to_string(pFFTChecks->get_fftOrder()), false);
	carrierAmplitudeTextEditor->setText(to_string(pFFTChecks->get_carrierAmplitude()), false);
	modulationIndexTextEditor->setText(to_string(pFFTChecks->get_modulationIndex()), false);
	_2i2_toggleButton->setToggleState
	(
		pFFTChecks->get_allIn1ToggleButtonToggleState()
		, juce::NotificationType::dontSendNotification
	);

	signalInCombinedPlotToggleButton->setToggleState
	(
		pFFTChecks->get_signal_in_combined_plot()
		, juce::NotificationType::dontSendNotification
	);

	signalInIndividualPlotToggleButton->setToggleState
	(
		pFFTChecks->get_signal_in_individual_plot()
		, juce::NotificationType::dontSendNotification
	);

	carrierInCombinedPlotToggleButton->setToggleState
	(
		pFFTChecks->get_carrier_in_combined_plot()
		, juce::NotificationType::dontSendNotification
	);

	carrierInIndividualPlotToggleButton->setToggleState
	(
		pFFTChecks->get_carrier_in_individual_plot()
		, juce::NotificationType::dontSendNotification
	);

	modulatedInCombinedPlotToggleButton->setToggleState
	(
		pFFTChecks->get_modulated_in_combined_plot()
		, juce::NotificationType::dontSendNotification
	);

	modulatedInIndividualPlotToggleButton->setToggleState
	(
		pFFTChecks->get_modulated_in_individual_plot()
		, juce::NotificationType::dontSendNotification
	);

	FFTInIndividualPlotToggleButton->setToggleState
	(
		pFFTChecks->get_FFT_in_individual_plot()
		, juce::NotificationType::dontSendNotification
	);

}

void controlPanel::doContButtonPresse()
{
	try
	{
		if (pFFTChecks->gen)
		{
			pFFTChecks->gen();
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
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="controlPanel" componentName=""
                 parentClasses="public juce::Component, public juce::TextEditor::Listener"
                 constructorParams="shared_ptr&lt;fftChecks&gt; pFFTChks" variableInitialisers="pFFTChecks(pFFTChks)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="350" initialHeight="440">
  <BACKGROUND backgroundColour="ff505050"/>
  <TEXTEDITOR name="maxTimeTextEditor" id="6e6d4251a2a6d380" memberName="maxTimeTextEditor"
              virtualName="" explicitFocusOrder="3" pos="72 94 95 24" tooltip="max time"
              initialText="max time" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="maxFreqTextEditor" id="7662909642b17a58" memberName="maxFreqTextEditor"
              virtualName="" explicitFocusOrder="4" pos="244 94 95 24" tooltip="mac freq"
              initialText="max freq" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="maxFreqLabel" id="47e631ed27d9284e" memberName="maxFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="175 94 53 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="maxTimeLabel" id="8b211e6878ea108a" memberName="maxTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 94 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="max time" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NFreqLabel" id="8269d5268144c2c3" memberName="NFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="130 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NFreq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NFreqValueLabel" id="87041ef7e2c8a83f" memberName="NFreqValueLabel"
         virtualName="" explicitFocusOrder="0" pos="189 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NFreq val&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NTimeLabel" id="9344a5060b2bb5ab" memberName="NTimeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 24 51 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NTime" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NTimeValueLabel" id="108bfc80744eb74a" memberName="NTimeValueLabel"
         virtualName="" explicitFocusOrder="0" pos="54 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NTime val&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="signalFreqLabel" id="668450732d3c0888" memberName="signalFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="0 125 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="signal freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="signalFreqTextEditor" id="2fdcec6ac9445576" memberName="signalFreqTextEditor"
              virtualName="" explicitFocusOrder="5" pos="72 124 95 24" tooltip="signal freq"
              initialText="signal freq" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="carrierFreqLabel" id="c12ced105cda4573" memberName="carrierFreqLabel"
         virtualName="" explicitFocusOrder="0" pos="175 125 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="carrier freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="carrierFreqTextEditor" id="e57cfdfa22e82311" memberName="carrierFreqTextEditor"
              virtualName="" explicitFocusOrder="6" pos="244 125 95 24" tooltip="carrier freq"
              initialText="carrier freq" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="NLabel" id="40e6abcc03fa6b5d" memberName="NLabel" virtualName=""
         explicitFocusOrder="0" pos="0 0 31 24" edTextCol="ff000000" edBkgCol="0"
         labelText="N" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="NValueLabel" id="5ab3e1029e95a04e" memberName="NValueLabel"
         virtualName="" explicitFocusOrder="0" pos="54 0 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="N value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="TsLabel" id="6cc132acc14ebea9" memberName="TsLabel" virtualName=""
         explicitFocusOrder="0" pos="130 0 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ts" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="TsValueLabel" id="f7bc0c1332c0edec" memberName="TsValueLabel"
         virtualName="" explicitFocusOrder="0" pos="189 0 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Ts value" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FsLabel" id="82146407bdd1a63a" memberName="FsLabel" virtualName=""
         explicitFocusOrder="0" pos="175 65 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Fs" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FFTOrderLabel" id="84558b9a0d701046" memberName="FFTOrderLabel"
         virtualName="" explicitFocusOrder="0" pos="0 65 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FFT Order" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="fftOrderTextEditor" id="e8633d879d3ce5fa" memberName="fftOrderTextEditor"
              virtualName="" explicitFocusOrder="1" pos="72 65 95 24" initialText="fft order"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="FsTextEditor" id="1fc9a7f281bcac4f" memberName="FsTextEditor"
              virtualName="" explicitFocusOrder="2" pos="244 65 95 24" initialText="Fs"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="contButton" id="6bbdd155c2eb5000" memberName="contButton"
              virtualName="" explicitFocusOrder="7" pos="72 394 95 24" buttonText="Continue"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="2i2_toggleButton" id="686966a11665c450" memberName="_2i2_toggleButton"
                virtualName="" explicitFocusOrder="0" pos="0 392 59 24" buttonText="2 i 1"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="defaultsTextButton" id="e1fa1deda629935b" memberName="defaultsTextButton"
              virtualName="" explicitFocusOrder="0" pos="244 394 95 24" buttonText="Defaults"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="sourceTypeComboBox" id="c19416213d612558" memberName="sourceTypeComboBox"
            virtualName="" explicitFocusOrder="0" pos="69 191 95 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="sourceTypeLabel" id="d3b82b3935ed45cf" memberName="sourceTypeLabel"
         virtualName="" explicitFocusOrder="0" pos="0 191 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="signal type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="modulationIndxLabel" id="898812a46d5c4e8e" memberName="modulationIndxLabel"
         virtualName="" explicitFocusOrder="0" pos="0 155 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="mod. idx." editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="modulationIndexTextEditor" id="ced4bcd26e259e34" memberName="modulationIndexTextEditor"
              virtualName="" explicitFocusOrder="5" pos="72 154 95 24" tooltip="modulation index"
              initialText="modulation index" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="carrierAmplitudeLabel" id="4858a1d702d428d2" memberName="carrierAmplitudeLabel"
         virtualName="" explicitFocusOrder="0" pos="175 154 70 24" edTextCol="ff000000"
         edBkgCol="0" labelText="carrier Amplt" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="carrierAmplitudeTextEditor" id="dff76cd7adfac146" memberName="carrierAmplitudeTextEditor"
              virtualName="" explicitFocusOrder="6" pos="244 154 95 24" tooltip="carrier amplt"
              initialText="carrier amplitude" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="signalInCombinedPlotToggleButton" id="91bf253e49e5ea30"
                memberName="signalInCombinedPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="77 256 32 24" tooltip="signal in combined plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="toPlotLabel" id="12eeb64bb19698b5" memberName="toPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="0 228 39 24" edTextCol="ff000000"
         edBkgCol="0" labelText="plot:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="inCombinedPlotLabel" id="35f4d0c78c8b0cd1" memberName="inCombinedPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="77 228 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="in combined plot" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="carrierInCombinedPlotToggleButton" id="f09b2a37ad1d55a6"
                memberName="carrierInCombinedPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="77 285 32 24" tooltip="carrier in combined plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="modulatedInCombinedPlotToggleButton" id="527790637ecf15de"
                memberName="modulatedInCombinedPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="77 315 32 24" tooltip="mpdulated in combined plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="signalInIndividualPlotToggleButton" id="1bfb9fc8fcf4602b"
                memberName="signalInIndividualPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="173 255 32 24" tooltip="signal in same plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="individualPlotLabel" id="7890dc15703afba2" memberName="individualPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="173 227 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="individual plot" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="carrierInIndividualPlotToggleButton" id="bc39508da2594682"
                memberName="carrierInIndividualPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="173 284 32 24" tooltip="carrier in individual plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="modulatedInIndividualPlotToggleButton" id="f567f00e93bc4c9a"
                memberName="modulatedInIndividualPlotToggleButton" virtualName=""
                explicitFocusOrder="0" pos="173 314 32 24" tooltip="mpdulated in individual plot"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="FFTInIndividualPlotToggleButton" id="262e405c530b61ff"
                memberName="FFTInIndividualPlotToggleButton" virtualName="" explicitFocusOrder="0"
                pos="173 344 32 24" tooltip="FFT in individual plot" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="signalPlotLabel" id="5eeb704e8de6a557" memberName="signalPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="0 255 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="signal" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="carrierPlotLabel" id="fc60e68daeb5ef26" memberName="carrierPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="0 285 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="carrier" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="modulatedPlotLabel" id="8d7cc5dcd1b0b91e" memberName="modulatedPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="0 315 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="modulated" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="FFTPlotLabel" id="b6334fa71b5771cb" memberName="FFTPlotLabel"
         virtualName="" explicitFocusOrder="0" pos="0 345 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FFT" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

