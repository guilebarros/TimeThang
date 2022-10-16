#include "TTGainPanel.h"
#include "TTParameters.h"


TTGainPanel::TTGainPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
}
TTGainPanel::~TTGainPanel()
{
    
}

void TTGainPanel::setParameterID(int inParameterID)
{
    mSlider = std::make_unique<TTParameterSlider>(mProcessor->parameters, TTParameterID[inParameterID]);
    const int slider_size = 54;
    
    mSlider->setBounds((getWidth() * 0.5 - (slider_size * 0.5)),
                       (getHeight() * 0.5 - (slider_size * 0.5)),
                       slider_size,
                       slider_size);
    addAndMakeVisible(mSlider.get());
}
