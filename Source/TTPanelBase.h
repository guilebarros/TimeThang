#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "TTInterfaceDefines.h"

class TTPanelBase
: public juce::Component

{
    
public:
    TTPanelBase(TimeThangAudioProcessor* inProcessor);
    ~TTPanelBase();
    
    void paint(juce::Graphics& g) override;
    
protected:
    
    TimeThangAudioProcessor* mProcessor;
};
