#pragma once
#include "TTHelper.h"

class TTLfo
{
public:
    
    TTLfo();
    ~TTLfo();
    
    void reset();
    void setSampleRate(double inSampleRate);
    void process(float inRate, float inDepth, float inNumSamples);
    
    float* getBuffer();
    
private:
    
    double mSampleRate;
    float mPhase;
    float mBuffer[maxBufferSize];
    
};
