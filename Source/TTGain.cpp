#include "TTGain.h"
#include <JuceHeader.h>

TTGain::TTGain()

{
    
}
TTGain::~TTGain()
{
    
}

void TTGain::process(float* inAudio,
             float inGain,
             float* outAudio,
             int inNumSamplesToRender)
{
    // mapeando ganho em dB
    
    float gainMapped = juce::jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f); //2o argumento: - infinnity
    
    for(int i = 0; i < inNumSamplesToRender; i++)
    {
        outAudio[i] = inAudio[i] * gainMapped; // usando o ganho mapeado
    }
}
