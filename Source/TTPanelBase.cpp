#include "TTPanelBase.h"

TTPanelBase::TTPanelBase(TimeThangAudioProcessor* inProcessor)
: mProcessor(inProcessor)

{
    
}
TTPanelBase::~TTPanelBase()
{
    
}

void TTPanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
}
