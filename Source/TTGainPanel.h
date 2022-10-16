#pragma once

#include "TTPanelBase.h"
#include "TTParameterSlider.h"

class TTGainPanel
: public TTPanelBase

{
    
public:
    
    TTGainPanel(TimeThangAudioProcessor* inProcessor);
    ~TTGainPanel();
    
    void setParameterID(int inParameterID);
    
private:
    
    std::unique_ptr<TTParameterSlider> mSlider;
};
