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
#include "fftChecks.h"
#include "controlPanel.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class controlPanelDocWin  : public juce::DocumentWindow
{
public:
    //==============================================================================
    controlPanelDocWin (juce::String name, shared_ptr<fftChecks> pFFTChks);
    ~controlPanelDocWin() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void closeButtonPressed() override
    {
        //setVisible(false);
    }
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    shared_ptr<controlPanel> p_controlPanel;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (controlPanelDocWin)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

