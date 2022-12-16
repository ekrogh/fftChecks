/*
  ==============================================================================

    fftChekGlobalEnums.h
    Created: 12 Dec 2022 11:21:25pm
    Author:  eigil

  ==============================================================================
*/

#pragma once

enum sourceTypes
{
    sinSource = 1
    , FMSource = 2
    , AMSource = 3
};

enum plotType
{
	plotTimeSignal
	, plotTimeCarrier
	, plotTimeModulated
	, plotFFT
};
