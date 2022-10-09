#pragma once
#include "TTPanelBase.h"
#include "TTTopPanel.h"
#include "TTGainPanel.h"
#include "TTCenterPanel.h"

class TTMainPanel
: public TTPanelBase
{
    
public:
    
    TTMainPanel(TimeThangAudioProcessor* inProcessor);
    ~TTMainPanel();
    
private:
    std::unique_ptr<TTTopPanel> mTopPanel;
    std::unique_ptr<TTGainPanel> mInputGainPanel;
    std::unique_ptr<TTGainPanel> mOutputGainPanel;
    std::unique_ptr<TTCenterPanel> mCenterPanel;
    
};
