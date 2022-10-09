#pragma once

enum TTParameter

{
    tParameter_InputGain = 0,
    tParameter_DelayTime,
    tParameter_DelayFeedback,
    tParameter_DelayWetDry,
    tParameter_DelayType, // chorus ou delay?
    tParameter_OutputGain,
    tParameter_ModulationRate,
    tParameter_ModulationDepth,
    tParameter_TotalNumParameters,
};

static juce::String TTParameterID[tParameter_TotalNumParameters] =
{
    "Input Gain",
    "Time",
    "Feedback",
    "Wet Dry",
    "Type",
    "Modulation Rate",
    "Modulation Depth",
};
