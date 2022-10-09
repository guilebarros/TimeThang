#pragma once
#include "TTPanelBase.h"
#include "TTCenterPanelMenuBar.h"
#include "TTFxPanel.h"

class TTCenterPanel
: public TTPanelBase

{
    
public:
    
    TTCenterPanel(TimeThangAudioProcessor* inProcessor);
    ~TTCenterPanel();
    
private:
    
    std::unique_ptr<TTCenterPanelMenuBar> mMenuBar;
    std::unique_ptr<TTFxPanel> mFxPanel;
    
};
