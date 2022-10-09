#include "TTCenterPanel.h"


TTCenterPanel::TTCenterPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);
    
    mMenuBar = std::make_unique<TTCenterPanelMenuBar>(inProcessor);
    mMenuBar->setTopLeftPosition(0, 0);
    addAndMakeVisible(mMenuBar.get());
    
    mFxPanel = std::make_unique<TTFxPanel>(inProcessor);
    mMenuBar->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
    addAndMakeVisible(mFxPanel.get());
}

TTCenterPanel::~TTCenterPanel()
{
    
}
