#include "TTFxPanel.h"


TTFxPanel::TTFxPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor),
  mStyle(tTTFxPanelStyle_Delay)
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

TTFxPanel::~TTFxPanel()
{
    
}

void TTFxPanel::paint(juce::Graphics& g)
{
    TTPanelBase::paint(g);
    
    switch (mStyle) {
            
        case(tTTFxPanelStyle_Delay):{
            g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
        }break;
            
        case(tTTFxPanelStyle_Chorus):{
            
            g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
            
        }break;
        
        default:
        case(tTTFxPanelStyle_TotalNumStyles): {
            // ferrou
            g.drawFittedText("no no no", 0, 0, getWidth(), getHeight(), juce::Justification::centred, 1);
            jassertfalse;
        }break;

    }
}

void TTFxPanel::setFxPanelStyle(TTFxPanelStyle inStyle)
{
    mStyle = inStyle;
}
