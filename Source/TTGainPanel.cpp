#include "TTGainPanel.h"


TTGainPanel::TTGainPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}
TTGainPanel::~TTGainPanel()
{
    
}
