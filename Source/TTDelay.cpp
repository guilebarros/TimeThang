#include "TTDelay.h"
#include <JuceHeader.h>
#include "TTHelper.h"

TTDelay::TTDelay()
: mSampleRate(-1),
  mFeedbackSample(0.0),
  mDelayIndex(0)
{
    
}
TTDelay::~TTDelay()
{
    
}

void TTDelay::setSampleRate(double inSampleRate)
{
    
    mSampleRate = inSampleRate;
    
}

void TTDelay::reset()
{
    
    juce::zeromem(mBuffer, (sizeof(double) * maxBufferDelaySize));
    
}

void TTDelay::process(float* inAudio,
                      float inTime,
                      float inFeedback,
                      float inWetDry,
                      float* outAudio,
                      int inNumSamplesToRender)
{
    const float wet = inWetDry;
    const float dry = 1.0f - wet;
    // o mapeamento para 0.95 é para evitar um feedback infinito
    const float feedbackMapped = juce::jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);
    
    // loop para iterar nos samples
    
    for(int i = 0; i < inNumSamplesToRender; i++)
    {
        const double delayTimeInSamples = (inTime * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);
        
        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        
        mFeedbackSample = sample;
        
        outAudio[i] = (inAudio[i] * dry + sample * wet);
        
        mDelayIndex = mDelayIndex + 1;
        
        if(mDelayIndex >= maxBufferDelaySize)
        {
            mDelayIndex = mDelayIndex - maxBufferDelaySize;
        }
    }
}

double TTDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
    double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
    
    if(readPosition < 0.0f)
    {
        readPosition += maxBufferDelaySize;
    }
    
    int index_y0 = (int)readPosition - 1;
    
    // checando o buffer circular
    
    if(index_y0 <= 0)
    {
        index_y0 += maxBufferDelaySize;
    }
    
    int index_y1 = readPosition;
    
    // se for maior do que o maior tamanho de buffer, volta ao inicio
    
    if(index_y1 > maxBufferDelaySize)
    {
        index_y1 = index_y1 - maxBufferDelaySize;
    }
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    
    const float t = readPosition - (int)readPosition;
    
    double outSample = tt_linear_interp(sample_y0, sample_y1, t);
    
    return outSample;
    
}
