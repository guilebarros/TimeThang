#pragma once

class TTGain
{
    
public:
    
    TTGain();
    ~TTGain();
    
    void process(float* inAudio,
                 float inGain,
                 float* outAudio,
                 int inNumSamplesToRender);
    
private:
    
    
};
