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

class fftChecks;

using namespace std;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class controlPanel  : public juce::Component,
                      public juce::TextEditor::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    controlPanel (shared_ptr<fftChecks> pFFTChks);
    ~controlPanel() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    /** Called when the user presses the return key. */
    void textEditorReturnKeyPressed(juce::TextEditor&) override;
    /** Called when the text editor loses focus. */
    void textEditorFocusLost(juce::TextEditor&) override;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void handleTextEditorKeyChgs(juce::TextEditor& textEditorWithReturn);
    void updateTimeValues();
    void updateFreqValues();
    void updateCarrierFreqValues();
    void updateSignalFreqValues();
    void updatefftOrderValues();
    void updateFsValues();
    void setDefaults();
    void displayAll();

    shared_ptr<fftChecks> pFFTChecks;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> contButton;
    std::unique_ptr<juce::ToggleButton> _2i2_toggleButton;
    std::unique_ptr<juce::TextEditor> maxTimeTextEditor;
    std::unique_ptr<juce::TextEditor> maxFreqTextEditor;
    std::unique_ptr<juce::Label> maxFreqLabel;
    std::unique_ptr<juce::Label> maxTimeLabel;
    std::unique_ptr<juce::Label> NFreqLabel;
    std::unique_ptr<juce::Label> NFreqValueLabel;
    std::unique_ptr<juce::Label> NTimeLabel;
    std::unique_ptr<juce::Label> NTimeValueLabel;
    std::unique_ptr<juce::TextButton> defaultsTextButton;
    std::unique_ptr<juce::Label> signalFreqLabel;
    std::unique_ptr<juce::TextEditor> signalFreqTextEditor;
    std::unique_ptr<juce::Label> carrierFreqLabel;
    std::unique_ptr<juce::TextEditor> carrierFreqTextEditor;
    std::unique_ptr<juce::Label> NLabel;
    std::unique_ptr<juce::Label> NValueLabel;
    std::unique_ptr<juce::Label> TsLabel;
    std::unique_ptr<juce::Label> TsValueLabel;
    std::unique_ptr<juce::Label> FsLabel;
    std::unique_ptr<juce::Label> FFTOrderLabel;
    std::unique_ptr<juce::TextEditor> fftOrderTextEditor;
    std::unique_ptr<juce::TextEditor> FsTextEditor;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (controlPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

