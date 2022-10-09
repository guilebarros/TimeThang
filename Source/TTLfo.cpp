#include "TTLfo.h"
#include<JuceHeader.h>

TTLfo::TTLfo()
{
    
    reset();
    
}

TTLfo::~TTLfo()
{
    
}


void TTLfo::reset()
{
    
    mPhase = 0.0f;
    juce::zeromem(mBuffer, sizeof(float) * maxBufferSize);
    
}


void TTLfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}


void TTLfo::process(float inRate, float inDepth, float inNumSamples)
{
    const float rate = juce::jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    
    for(int i = 0; i < inNumSamples; i++)
    {
        mPhase = mPhase + (rate / mSampleRate);
        
        if(mPhase > 1.0f)
        {
            mPhase = mPhase - 1.0f;
        }
        
        const float lfoPosition = sinf(mPhase * TT2PI) * inDepth;
        mBuffer[i] = lfoPosition;
    }
    
}

float* TTLfo::getBuffer()
{
    return mBuffer;
}
