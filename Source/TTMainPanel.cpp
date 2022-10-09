#include "TTMainPanel.h"


TTMainPanel::TTMainPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mTopPanel = std::make_unique<TTTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    
    //mMainPanel->setBounds(0,0,MAIN_PANEL_WIDTH,MAIN_PANEL_HEIGHT);
    
    //mMainPanel->setName("example");
    
    addAndMakeVisible(mTopPanel.get());
}
TTMainPanel::~TTMainPanel()
{
    
}
