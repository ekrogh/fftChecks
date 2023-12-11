/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

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
	toFront(true);
    //[/Constructor]
}

fftChecks::~fftChecks()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
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
	resizePlots();
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


fftChecks::Generator<uint64_t>
fftChecks::plotCoRoutine()
{
	while (true)
	{
		switch (sourceType)
		{
			case sinSource:
			{
				doFillSine();
				break;
			}
			case FMSource:
			{
				doFillFM();
				break;
			}
			case AMSource:
			{
				doFillAM();
				break;
			}
			default:
				break;
		}

		if (allIn1ToggleButtonToggleState)
		{
			if (y_individualPlots.size() != 0)
			{
				auto idx = 0;
				for (auto y_values : y_individualPlots)
				{
					shared_ptr<cmp::Plot> m_individualPlot = make_shared<cmp::Plot>();
					addAndMakeVisible(m_individualPlot.get());
					m_individualPlot->plot({ y_values }, { x_individualPlots[idx] });
					m_individualPlot->setGridType(cmp::GridType::grid);
					m_individualPlot->setTitle(titlePlotsIndividual[idx++]);
					allPlots.push_back(m_individualPlot);
				}
			}
			if (y_combinedPlots.size() != 0)
			{
				shared_ptr<cmp::Plot> m_combinedPlots = make_shared<cmp::Plot>();
				addAndMakeVisible(m_combinedPlots.get());
				m_combinedPlots->plot(y_combinedPlots, x_combinedPlots);
				m_combinedPlots->setGridType(cmp::GridType::grid);

				string theTitle = "";
				string theSeperator = "";
				for (auto thisTitle : titlePlotsCombined)
				{
					theTitle += theSeperator + thisTitle;
					theSeperator = "  and  ";
				}
				m_combinedPlots->setTitle(theTitle);

				allPlots.push_back(m_combinedPlots);
			}

			if (allPlots.size() != 0)
			{
				resizePlots();
			}

			co_yield 1;

		}
		else
		{
			if (y_individualPlots.size() != 0)
			{
				auto idx = 0;
				for (auto y_values : y_individualPlots)
				{
					removeAllPlots();

					shared_ptr<cmp::Plot> m_individualPlot = make_shared<cmp::Plot>();
					addAndMakeVisible(m_individualPlot.get());
					m_individualPlot->plot({ y_values }, { x_individualPlots[idx] });
					m_individualPlot->setGridType(cmp::GridType::grid);
					m_individualPlot->setTitle(titlePlotsIndividual[idx++]);
					allPlots.push_back(m_individualPlot);

					resizePlots();

					co_yield 3;

				}
			}
			if (y_combinedPlots.size() != 0)
			{
				shared_ptr<cmp::Plot> m_combinedPlots = make_shared<cmp::Plot>();
				addAndMakeVisible(m_combinedPlots.get());
				m_combinedPlots->plot(y_combinedPlots, x_combinedPlots);
				m_combinedPlots->setGridType(cmp::GridType::grid);

				string theTitle = "";
				string theSeperator = "";
				for (auto thisTitle : titlePlotsCombined)
				{
					theTitle += theSeperator + thisTitle;
					theSeperator = "  and  ";
				}
				m_combinedPlots->setTitle(theTitle);

				allPlots.push_back(m_combinedPlots);

				resizePlots();

				co_yield 2;

			}
		}

		deleteAllPlots();
	}
}

void fftChecks::doFillSine()
{
	deleteAllPlots();

	doSineTimeFillPlotData();
	doSineFFTFillPlotData();
}

void fftChecks::doFillFM()
{
	deleteAllPlots();

	doSignalTimeFillPlotData();
	doCarrierTimeFillPlotData();
	doFMTimeFillPlotData();
	doFMFFTFillPlotData();
}

void fftChecks::doFillAM()
{
	deleteAllPlots();

	doSignalTimeFillPlotData();
	doCarrierTimeFillPlotData();
	doAMTimeFillPlotData();
	doAMFFTFillPlotData();
}

void fftChecks::doSignalTimeFillPlotData()
{
	// FM signal
	fillYSignalSin();
	fillXTime();

	if (plot_signal)
	{
		auto sgnlStr = std::to_string(signalSinFreq);
		auto titleTxt = "Signal (" + sgnlStr + " Hz) Time domain";

		if (signal_in_individual_plot)
		{
			y_individualPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_individualPlots.push_back(x_ticksTime);
			titlePlotsIndividual.push_back(titleTxt);
		}
		if (signal_in_combined_plot)
		{
			y_combinedPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_combinedPlots.push_back(x_ticksTime);
			titlePlotsCombined.push_back(titleTxt);
		}

	}
}

void fftChecks::doCarrierTimeFillPlotData()
{
	// FM signal
	fillYCarrierSin();
	fillXTime();

	if (plot_carrier)
	{
		auto crrrStr = std::to_string(carrierSinFreq);
		auto titleTxt = "Carrier (" + crrrStr + " Hz) Time domain";

		if (carrier_in_individual_plot)
		{
			y_individualPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_individualPlots.push_back(x_ticksTime);
			titlePlotsIndividual.push_back(titleTxt);
		}
		if (carrier_in_combined_plot)
		{
			y_combinedPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_combinedPlots.push_back(x_ticksTime);
			titlePlotsCombined.push_back(titleTxt);
		}
	}
}

void fftChecks::doFMTimeFillPlotData()
{
	// FM signal
	fillYFM();
	fillXTime();

	if (plot_modulated)
	{
		if (modulated_in_individual_plot)
		{
			y_individualPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_individualPlots.push_back(x_ticksTime);
			titlePlotsIndividual.push_back("Modulated Time domain");
		}
		if (modulated_in_combined_plot)
		{
			y_combinedPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_combinedPlots.push_back(x_ticksTime);
			titlePlotsCombined.push_back("Modulated Time domain");
		}
	}
}

void fftChecks::doFMFFTFillPlotData()
{
	//FFT
	fillYFM();
	fillXFrequency();

	hannWinn(fftbfr);
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	if (plot_FFT)
	{
		if (FFT_in_individual_plot)
		{
			auto toPlot = vector<float>(fftbfr, fftbfr + NFreq);

			auto result = ranges::max_element(toPlot);
			auto idxMax = ranges::distance(toPlot.begin(), result);
			auto freqAtMax = deltaFreq * (double)idxMax;

			auto strFreqAtMax = std::to_string(freqAtMax);
			auto theTitle = "FFT (max at " + strFreqAtMax + " Hz) Modulated";

			y_individualPlots.push_back(toPlot);
			x_individualPlots.push_back(x_ticksFFT);
			titlePlotsIndividual.push_back(theTitle);
		}
	}
}

void fftChecks::doAMTimeFillPlotData()
{
	// FM signal
	fillYAM();
	fillXTime();

	if (plot_modulated)
	{
		if (modulated_in_individual_plot)
		{
			y_individualPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_individualPlots.push_back(x_ticksTime);
			titlePlotsIndividual.push_back("Modulated Time domain");
		}
		if (modulated_in_combined_plot)
		{
			y_combinedPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_combinedPlots.push_back(x_ticksTime);
			titlePlotsCombined.push_back("Modulated Time domain");
		}
	}
}

void fftChecks::doAMFFTFillPlotData()
{
	//FFT
	fillYAM();
	fillXFrequency();

	hannWinn(fftbfr);
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	if (plot_FFT)
	{
		if (FFT_in_individual_plot)
		{
			auto toPlot = vector<float>(fftbfr, fftbfr + NFreq);

			auto result = ranges::max_element(toPlot);
			auto idxMax = ranges::distance(toPlot.begin(), result);
			auto freqAtMax = deltaFreq * (double)idxMax;

			auto strFreqAtMax = std::to_string(freqAtMax);
			auto theTitle = "FFT (max at " + strFreqAtMax + " Hz) Modulated";

			y_individualPlots.push_back(toPlot);
			x_individualPlots.push_back(x_ticksFFT);
			titlePlotsIndividual.push_back(theTitle);
		}
	}
}

void fftChecks::doSineTimeFillPlotData()
{
	fillYSignalSin();
	fillXTime();

	if (plot_signal)
	{
		auto sgnlStr = std::to_string(signalSinFreq);
		auto titleTxt = "Sin (" + sgnlStr + " Hz) Time domain";

		if (signal_in_individual_plot)
		{
			y_individualPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_individualPlots.push_back(x_ticksTime);
			titlePlotsIndividual.push_back(titleTxt);
		}
		if (signal_in_combined_plot)
		{
			y_combinedPlots.push_back(vector<float>(fftbfr, fftbfr + NTime));
			x_combinedPlots.push_back(x_ticksTime);
			titlePlotsCombined.push_back(titleTxt);
		}
	}
}

void fftChecks::doSineFFTFillPlotData()
{
	fillXFrequency();
	fillYSignalSin();

	hannWinn(fftbfr);
	forwardFFT->performFrequencyOnlyForwardTransform(fftbfr, true);

	if (plot_FFT)
	{
		if (FFT_in_individual_plot)
		{
			auto toPlot = vector<float>(fftbfr, fftbfr + NFreq);

			auto result = ranges::max_element(toPlot);
			auto idxMax = ranges::distance(toPlot.begin(), result);
			auto freqAtMax = deltaFreq * (double)idxMax;

			auto strFreqAtMax = std::to_string(freqAtMax);
			auto theTitle = "FFT (max at " + strFreqAtMax + " Hz) Sin";

			y_individualPlots.push_back(toPlot);
			x_individualPlots.push_back(x_ticksFFT);
			titlePlotsIndividual.push_back(theTitle);
		}
	}
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

void fftChecks::makeYTickLabels(vector<float>& y_modulated)
{
	auto [minY, maxY] = ranges::minmax_element(y_modulated);

	auto tickStep = (*maxY - *minY) / 10.0f;

	for (int i = 0; i <= 10; i++)
	{
		yTickLabels.push_back(to_string((float)i * tickStep));
	}
}

void fftChecks::fillYSignalSin()
{
	double curPhaseSignalSinFreq = 0.0f;

	std::memset(fftbfr, 0, N * 2 * sizeof(float));

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] = (float)(sin(curPhaseSignalSinFreq) * signalAmplitude);

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);
	}
}

void fftChecks::fillYCarrierSin()
{
	double curPhaseCarrierSinFreq = 0.0f;

	std::memset(fftbfr, 0, N * 2 * sizeof(float));

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] = (float)(sin(curPhaseCarrierSinFreq) * carrierAmplitude);

		curPhaseCarrierSinFreq =
			fmod((curPhaseCarrierSinFreq + carrierSinFreqDeltaRad), twoPi);
	}
}

void fftChecks::fillYFM()
{
	double curSignalSin = 0.0f;
	double curPhaseSignalSinFreq = 0.0f;
	double curPhaseCarrier = 0.0f;
	double curFMPhase = 0.0f;

	std::memset(fftbfr, 0, N * 2 * sizeof(float));

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] =
			(float)(carrierAmplitude * cos(curFMPhase));

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);
		curSignalSin =
			sin(curPhaseSignalSinFreq);

		curPhaseCarrier =
			curPhaseCarrier + carrierSinFreqDeltaRad;

		curFMPhase =
			fmod((curPhaseCarrier + signalAmplitude * curSignalSin), twoPi);

	}
}

void fftChecks::fillYAM()
{
	double curSignalSin = 0.0f;
	double curPhaseSignalSinFreq = 0.0f;
	double curPhaseCarrier = 0.0f;
	double curCarrierSin = 0.0f;

	std::memset(fftbfr, 0, N * 2 * sizeof(float));

	for (int i = 0; i < N; i++)
	{
		fftbfr[i] =
			(float)(carrierAmplitude * curCarrierSin * signalAmplitude * curSignalSin);

		curPhaseSignalSinFreq =
			fmod((curPhaseSignalSinFreq + signalSinFreqDeltaRad), twoPi);
		curSignalSin =
			sin(curPhaseSignalSinFreq);

		curPhaseCarrier =
			fmod((curPhaseCarrier + carrierSinFreqDeltaRad), twoPi);
		curCarrierSin =
			sin(curPhaseCarrier);

	}
}

void fftChecks::hannWinn(float* fftBfrToWin)
{
	double hannWinDlta = (double)(numbers::pi) / (double)(N - 1);
	double curPhaseHannWin = 0.0f;

	for (int i = 0; i < N; i++)
	{
		fftBfrToWin[i] *= (float)pow(std::sin(curPhaseHannWin), 2);

		curPhaseHannWin =
			fmod((curPhaseHannWin + hannWinDlta), twoPi);
	}
}

void fftChecks::resizePlots()
{
	int noPlotsActive = (int)(allPlots.size());

	if (noPlotsActive > 0)
	{
		auto bnds = getBounds();

		auto heights = bnds.getHeight() / noPlotsActive;

		bnds.setHeight(heights);

		for (auto thisPlot : allPlots)
		{
			thisPlot->setBounds(bnds);
			bnds.setY(bnds.getY() + heights);
		}
	}
}

void fftChecks::deleteAllPlots()
{
	auto noPlotsActive = allPlots.size();

	if (noPlotsActive != 0)
	{
		for (auto thisPlot : allPlots)
		{
			removeMouseListener(thisPlot.get());
			removeChildComponent(thisPlot.get());
		}
		allPlots.clear();

		y_combinedPlots.clear();
		x_combinedPlots.clear();
		y_individualPlots.clear();
		x_individualPlots.clear();
		titlePlotsIndividual.clear();
		titlePlotsCombined.clear();

		yTickLabels.clear();
		x_ticksTime.clear();
		x_ticksFFT.clear();

	}
}

void fftChecks::removeAllPlots()
{
	auto noPlotsActive = allPlots.size();

	if (noPlotsActive != 0)
	{
		for (auto thisPlot : allPlots)
		{
			removeMouseListener(thisPlot.get());
			removeChildComponent(thisPlot.get());
		}
		allPlots.clear();
	}
}


void fftChecks::updatefftOrderValues()
{
	forwardFFT = make_unique<juce::dsp::FFT>(fftOrder);
	N = forwardFFT->getSize(); // No of points in fft
	deltaFreq = ((double)Fs / ((double)N - (double)1));
	NFreq = (int)(maxFreq / deltaFreq);
	free(fftbfr);
	fftbfr = (float*)calloc(N * 2, sizeof(float));
}

void fftChecks::updateFsValues()
{
	Ts = (double)1.0f / (double)Fs;
	deltaFreq = ((double)Fs / ((double)N - (double)1));
	NTime = (int)(maxTime / Ts);
	NFreq = (int)(maxFreq / deltaFreq);

	signalSinFreqDeltaRad =
		signalSinFreq * twoPi * Ts;
	carrierSinFreqDeltaRad =
		carrierSinFreq * twoPi * Ts;
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

