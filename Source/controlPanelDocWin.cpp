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
//[/Headers]

#include "controlPanelDocWin.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
controlPanelDocWin::controlPanelDocWin (juce::String name, shared_ptr<fftChecks> pFFTChks)
    : DocumentWindow (name, juce::Desktop::getInstance().getDefaultLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId), DocumentWindow::allButtons)
{
    //[Constructor_pre] You can add your own custom stuff here..
    setUsingNativeTitleBar(true);
    p_controlPanel = make_shared<controlPanel>(pFFTChks);
    setContentOwned(p_controlPanel.get(), true);
    //[/Constructor_pre]


    //[UserPreSize]
#if JUCE_IOS || JUCE_ANDROID
    setFullScreen(true);
#else
    //[/UserPreSize]

    setSize (350, 440);


    //[Constructor] You can add your own custom stuff here..
    centreWithSize(getWidth(), getHeight());
    auto bnds = getBounds();
    bnds.setX(0);
    setBounds(bnds);
#endif

    setVisible(true);
    toFront(false);
    //[/Constructor]
}

controlPanelDocWin::~controlPanelDocWin()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void controlPanelDocWin::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void controlPanelDocWin::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="controlPanelDocWin" componentName=""
                 parentClasses="public juce::DocumentWindow" constructorParams="juce::String name, shared_ptr&lt;fftChecks&gt; pFFTChks"
                 variableInitialisers="DocumentWindow (name, juce::Desktop::getInstance().getDefaultLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId), DocumentWindow::allButtons)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="350" initialHeight="440">
  <BACKGROUND backgroundColour="ff505050"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

