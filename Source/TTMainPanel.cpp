#include "TTMainPanel.h"


TTMainPanel::TTMainPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    // top panel
    
    mTopPanel = std::make_unique<TTTopPanel>(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());
    
    // gain panel
    
    mInputGainPanel = std::make_unique<TTGainPanel>(inProcessor);
    mInputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mInputGainPanel.get());
    
    mOutputGainPanel = std::make_unique<TTGainPanel>(inProcessor);
    mOutputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mOutputGainPanel.get());
    
    // main panel
    
    mCenterPanel = std::make_unique<TTCenterPanel>(inProcessor);
    mCenterPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
    addAndMakeVisible(mCenterPanel.get());
    
    
}
TTMainPanel::~TTMainPanel()
{
    
}
