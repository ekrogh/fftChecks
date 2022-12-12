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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 1000);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

fftChecks::~fftChecks()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	//p_controlPanelDocWin.reset();
	std::free(fftbfr);
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
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


fftChecks::Generator<uint64_t>
fftChecks::plotCoRoutine()
{
	while (true)
	{
		if (allIn1ToggleButtonToggleState)
		{
			doSine();
			co_yield 1;

			doFM();
			co_yield 2;
		}
		else
		{
			doSineTime();
			co_yield 3;

			doSineFFT();
			co_yield 4;

			doFMSignalTime();
			co_yield 5;

			doFMCarrierTime();
			co_yield 6;

			doFMTime();
			co_yield 7;

			doFMFFT();
			co_yield 8;

		}

		deletePlots();
		co_yield 9;
	}
}

void fftChecks::doSine()
{
	deletePlots();

	doSineTime();
	doSineFFT();
}

void fftChecks::doFM()
{
	deletePlots();

	doFMSignalTime();
	doFMCarrierTime();
	doFMTime();
	doFMFFT();
}

void fftChecks::doFMSignalTime()
{
	initNewPlot(plotTimeSignal);

	// FM signal
	fillYFMSignalSin();
	fillXTime();

	// Plot signal
	y_data = vector<float>(fftbfr, fftbfr + NTime);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTimeSignal->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTimeSignal->setTitle("FM Signal Time domain");
	m_plotTimeSignal->plot({ y_data }, { x_ticksTime });
	m_plotTimeSignal->gridON(true, false);
}

void fftChecks::doFMCarrierTime()
{
	initNewPlot(plotTimeCarrier);

	// FM signal
	fillYCarrierSin();
	fillXTime();

	// Plot signal
	y_data = vector<float>(fftbfr, fftbfr + NTime);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTimeCarrier->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTimeCarrier->setTitle("FM Carrier Time domain");
	m_plotTimeCarrier->plot({ y_data }, { x_ticksTime });
	m_plotTimeCarrier->gridON(true, false);
}

void fftChecks::doFMTime()
{
	initNewPlot(plotTimeFM);

	fillYFMSignalSin();
	auto y_FMSignalSin = vector<float>(fftbfr, fftbfr + NTime);
	// FM signal
	fillYFM();
	fillXTime();

	// Plot signal
	y_data = vector<float>(fftbfr, fftbfr + NTime);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTimeFM->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTimeFM->setTitle("FM Time domain");
	m_plotTimeFM->plot({ y_data, y_FMSignalSin }, { x_ticksTime });
	m_plotTimeFM->gridON(true, false);
}

void fftChecks::doFMFFT()
{
	initNewPlot(plotFFT);

	//FFT
	fillYFM();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + NFreq);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotFFT->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotFFT->setTitle("FM Freq domain");
	m_plotFFT->plot({ y_data }, { x_ticksFFT });
	m_plotFFT->gridON(true, false);
}

void fftChecks::doSineTime()
{
	initNewPlot(plotTimeSignal);

	fillYSignalSin();
	fillXTime();

	y_data = vector<float>(fftbfr, fftbfr + NTime);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotTimeSignal->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotTimeSignal->setTitle("Sin Time domain");
	m_plotTimeSignal->plot({ y_data }, { x_ticksTime });
	m_plotTimeSignal->gridON(true, false);
}

void fftChecks::doSineFFT()
{
	initNewPlot(plotFFT);

	fillYSignalSin();
	fillXFrequency();
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	// Plot FFT
	y_data = vector<float>(fftbfr, fftbfr + NFreq);
	auto minYmaxY = ranges::minmax_element(y_data);
	m_plotFFT->yLim(*minYmaxY.min, *minYmaxY.max);
	m_plotFFT->setTitle("Sin Freq domain");
	m_plotFFT->plot({ y_data }, { x_ticksFFT });
	m_plotFFT->gridON(true, false);
}


void fftChecks::fillXFrequency()
{
	x_ticksFFT = vector<float>(NFreq);

	int n = 0;
	ranges::generate(x_ticksFFT, [&n, this]() { return (float)(deltaFreq * n++); });
}

void fftChecks::fillXTime()
{
	x_ticksTime = vector<float>(NTime);

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

void fftChecks::fillYSignalSin()
{
	double curPhaseSignalSinFreq = 0.0f;
	double hannWinDlta = (double)(numbers::pi) / (double)(N - 1);
	double curPhaseHannWin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] =
			(float)sin(curPhaseSignalSinFreq)
			* pow(std::sin(curPhaseHannWin), 2);

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);

		curPhaseHannWin =
			fmod((curPhaseHannWin + hannWinDlta), twoPi);
	}
}

void fftChecks::fillYCarrierSin()
{
	double curPhaseCarrierSinFreq = 0.0f;
	double hannWinDlta = (double)(numbers::pi) / (double)(N - 1);
	double curPhaseHannWin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] =
			(float)sin(curPhaseCarrierSinFreq)
			* pow(std::sin(curPhaseHannWin), 2);

		curPhaseCarrierSinFreq =
			fmod((curPhaseCarrierSinFreq + carrierSinFreqDeltaRad), twoPi);

		curPhaseHannWin =
			fmod((curPhaseHannWin + hannWinDlta), twoPi);
	}
}

void fftChecks::fillYFMSignalSin()
{
	double curPhaseSignalSinFreq = 0.0f;
	double hannWinDlta = (double)(numbers::pi) / (double)(N - 1);
	double curPhaseHannWin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] =
			(float)(((sin(curPhaseSignalSinFreq) / (double)2.0f) + (double)0.5f)
				* pow(sin(curPhaseHannWin), 2));

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);

		curPhaseHannWin =
			fmod((curPhaseHannWin + hannWinDlta), twoPi);
	}
}

void fftChecks::fillYFM()
{
	double curSignalSin = 0.0f;
	double curPhaseSignalSinFreq = 0.0f;
	double curPhaseCarrierSinFreq = 0.0f;
	double curCarrierSin = 0.0f;
	double hannWinDlta = (double)(numbers::pi) / (double)(N - 1);
	double curPhaseHannWin = 0.0f;
	double curHannWinSin = 0.0f;
	double curFMPhase = 0.0f;
	double curFM = 0.0f;
	float curWinndFM = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] = curWinndFM;

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);
		curSignalSin =
			(sin(curPhaseSignalSinFreq) / (double)2.0f) + (double)0.5f;

		curPhaseCarrierSinFreq =
			curPhaseCarrierSinFreq + carrierSinFreqDeltaRad;
		//fmod((curPhaseCarrierSinFreq + carrierSinFreqDeltaRad), twoPi);
		//curCarrierSin =
		//	sin(curPhaseCarrierSinFreq);

		curFMPhase =
			fmod(curPhaseCarrierSinFreq * curSignalSin, twoPi);
		curFM =
			sin(curFMPhase);

		curPhaseHannWin =
			fmod((curPhaseHannWin + hannWinDlta), twoPi);
		curHannWinSin =
			sin(curPhaseHannWin);

		curWinndFM =
			(float)(curFM * curHannWinSin);
	}
}

void fftChecks::initNewPlot(plotType toDo)
{

	if (!allIn1ToggleButtonToggleState)
	{
		deletePlots();
	}

	switch (toDo)
	{
		case fftChecks::plotTimeSignal:
			{
				m_plotTimeSignal = make_shared<cmp::Plot>();
				allPlots.push_back(m_plotTimeSignal);
				addAndMakeVisible(m_plotTimeSignal.get());
				break;
			}
		case fftChecks::plotTimeCarrier:
			{
				m_plotTimeCarrier = make_shared<cmp::Plot>();
				allPlots.push_back(m_plotTimeCarrier);
				addAndMakeVisible(m_plotTimeCarrier.get());
				break;
			}
		case fftChecks::plotTimeFM:
			{
				m_plotTimeFM = make_shared<cmp::Plot>();
				allPlots.push_back(m_plotTimeFM);
				addAndMakeVisible(m_plotTimeFM.get());
				break;
			}
		case fftChecks::plotFFT:
			{
				m_plotFFT = make_shared<cmp::Plot>();
				allPlots.push_back(m_plotFFT);
				addAndMakeVisible(m_plotFFT.get());
				break;
			}
		default:
			{
				break;
			}
	}
	resizePlotWindow();
}

void fftChecks::resizePlotWindow()
{
	auto noPlotsActive = allPlots.size();
	auto bnds = getBounds();

	auto heights = bnds.getHeight() / noPlotsActive;

	bnds.setHeight(heights);

	for (size_t i = 0; i < noPlotsActive; i++)
	{
		allPlots[i]->setBounds(bnds);
		bnds.setY(bnds.getY() + heights);
	}
}

void fftChecks::deletePlots()
{
	auto noPlotsActive = allPlots.size();

	if (noPlotsActive != 0)
	{
		for (size_t i = 0; i < noPlotsActive; i++)
		{
			removeMouseListener(allPlots[i].get());
			removeChildComponent(allPlots[i].get());
		}
		allPlots.clear();

		m_plotTimeSignal.reset();
		m_plotTimeCarrier.reset();
		m_plotTimeFM.reset();
		m_plotFFT.reset();
	}
}


void fftChecks::updatefftOrderValues()
{
	forwardFFT = make_unique<juce::dsp::FFT>(fftOrder);
	N = forwardFFT->getSize(); // No of points in fft
	maxTime = (double)N * Ts;
	NTime = (int)(maxTime / Ts);
	deltaFreq = ((double)Fs / ((double)N - (double)1));
	NFreq = (int)(maxFreq / deltaFreq);
	free(fftbfr);
	fftbfr = (float*)calloc(N * 2, sizeof(float));
}

void fftChecks::updateFsValues()
{
	Ts = (double)1.0f / (double)Fs;
	maxTime = (double)N * Ts;
	NTime = (int)(maxTime / Ts);
	deltaFreq = ((double)Fs / ((double)N - (double)1));
	maxFreq = (double)(Fs >> 1);
	NFreq = (int)(maxFreq / deltaFreq);
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

