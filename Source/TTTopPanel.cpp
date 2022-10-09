#include "TTTopPanel.h"


TTTopPanel::TTTopPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}
TTTopPanel::~TTTopPanel()
{
    
}

void TTTopPanel::paint(juce::Graphics& g)
{
    TTPanelBase::paint(g);
    g.drawFittedText("TIME THANG", 0, 0, getWidth() - 10, getHeight(), juce::Justification::centredRight, 1);
}
