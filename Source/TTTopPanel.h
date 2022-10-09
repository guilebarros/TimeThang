#pragma once
#include "TTPanelBase.h"

class TTTopPanel
: public TTPanelBase

{
    
public:
    
    TTTopPanel(TimeThangAudioProcessor* inProcessor);
    ~TTTopPanel();
    
    void paint(juce::Graphics& g) override;
    
private:
    
    
};
