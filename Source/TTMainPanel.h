#pragma once
#include "TTPanelBase.h"
#include "TTTopPanel.h"

class TTMainPanel
: public TTPanelBase
{
    
public:
    
    TTMainPanel(TimeThangAudioProcessor* inProcessor);
    ~TTMainPanel();
    
private:
    std::unique_ptr<TTTopPanel> mTopPanel;
    
};
