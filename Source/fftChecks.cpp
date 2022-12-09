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

	contButton.reset(new juce::TextButton("contButton"));
	addAndMakeVisible(contButton.get());
	contButton->setButtonText(TRANS("Continue"));
	contButton->addListener(this);

	contButton->setBounds(448, 840, 150, 24);


	//[UserPreSize]
	//[/UserPreSize]

	setSize(1200, 1000);


	//[Constructor] You can add your own custom stuff here..
	initNewPlot();
	//[/Constructor]
}

fftChecks::~fftChecks()
{
	//[Destructor_pre]. You can add your own custom destruction code here..
	std::free(fftbfr);
	//[/Destructor_pre]

	contButton = nullptr;


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
	//[/UserResized]
}

void fftChecks::buttonClicked(juce::Button* buttonThatWasClicked)
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

	//[UserbuttonClicked_Post]
	//[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

Generator<uint64_t>
fftChecks::plotCoRoutine()
{
	doSine();
	co_yield 2;

	doFM();
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
	juce::MessageManagerLock mml;

	// FM signal
	fillYFM();
	fillXTime();

	// Plot signal
	y_data = vector<float>(fftbfr, fftbfr + N);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTime->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTime->setTitle("FM Time domain");
	m_plotTime->plot({ y_data }, { x_ticksTime });
	m_plotTime->gridON(true, false);
}

void fftChecks::doFMFFT()
{
	// Wait for cont button to be clicked...
	juce::MessageManagerLock mml;

	//FFT
	fillYFM();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + (N >> 1));
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotFFT->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotFFT->setTitle("FM Freq domain");
	m_plotFFT->plot({ y_data }, { x_ticksFFT });
	m_plotFFT->gridON(true, false);
}

void fftChecks::doSineTime()
{
	juce::MessageManagerLock mml;

	fillYSin();
	fillXTime();

	y_data = vector<float>(fftbfr, fftbfr + N);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTime->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTime->setTitle("Sin Time domain");
	m_plotTime->plot({ y_data }, { x_ticksTime });
	m_plotTime->gridON(true, false);
}

void fftChecks::doSineFFT()
{
	juce::MessageManagerLock mml;

	fillYSin();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + (N >> 1));
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotFFT->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotFFT->setTitle("Sin Freq domain");
	m_plotFFT->plot({ y_data }, { x_ticksFFT });
	m_plotFFT->gridON(true, false);
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
	// Remove evt. old plot
	//juce::MessageManagerLock mml;
	//removeChildComponent(m_plotTime.get());
	m_plotTime = make_unique< cmp::Plot>();
	addAndMakeVisible(m_plotTime.get());

	m_plotFFT = make_unique< cmp::Plot>();
	addAndMakeVisible(m_plotFFT.get());

	resizePlotWindow();
}

void fftChecks::resizePlotWindow()
{
	//[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]

	//[UserResized] Add your own custom resize handling here..

	auto heightForPlots = contButton->getY();
	auto heightForOnePlot = heightForPlots / 2;

	auto plotTimeBnds = getBounds();
	plotTimeBnds.setHeight(heightForOnePlot);
	plotTimeBnds.setY(0);
	m_plotTime->setBounds(plotTimeBnds);

	auto plotFFTBnds = getBounds();
	plotFFTBnds.setHeight(heightForOnePlot);
	plotFFTBnds.setY(heightForOnePlot);
	m_plotFFT->setBounds(plotFFTBnds);

	//[/UserResized]
}

void fftChecks::deletePlot()
{
	removeAllChildren();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

	This is where the Projucer stores the metadata that describe this GUI layout, so
	make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="fftChecks" componentName=""
				 parentClasses="public juce::Component, private juce::Thread"
				 constructorParams="" variableInitialisers="Thread(&quot;fftCheck&quot;)"
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

