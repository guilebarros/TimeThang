#pragma once
#include "TTPanelBase.h"

enum TTFxPanelStyle
{
    tTTFxPanelStyle_Delay,
    tTTFxPanelStyle_Chorus,
    tTTFxPanelStyle_TotalNumStyles
};

class TTFxPanel
: public TTPanelBase

{
public:
    
    TTFxPanel(TimeThangAudioProcessor* inProcessor);
    ~TTFxPanel();
    
    void paint(juce::Graphics& g) override;
    
    void setFxPanelStyle(TTFxPanelStyle inStyle);
    
private:
    
    TTFxPanelStyle mStyle;
};
