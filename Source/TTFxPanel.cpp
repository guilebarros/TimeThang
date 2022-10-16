#include "TTFxPanel.h"
#include "TTParameters.h"


TTFxPanel::TTFxPanel(TimeThangAudioProcessor* inProcessor)
: TTPanelBase(inProcessor)
  
{
    setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
    
    setFxPanelStyle(tTTFxPanelStyle_Delay);
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
    
    mSliders.clear();
    
    const int slider_size = 56;
    int x = 130;
    int y = (getHeight() * 0.5) - (slider_size * 0.5);
    
    
    switch (mStyle) {
            
        case(tTTFxPanelStyle_Delay):{
            
            TTParameterSlider* time =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_DelayTime]);
            time->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(time);
            mSliders.add(time);
            
            x = x + (slider_size * 2 );
            
            TTParameterSlider* feedback =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_DelayFeedback]);
            feedback->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(feedback);
            mSliders.add(feedback);
            x = x + (slider_size * 2 );
            
            TTParameterSlider* wetdry =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            x = x + (slider_size * 2 );
            
        } break;
            
        case(tTTFxPanelStyle_Chorus):{
            
            TTParameterSlider* rate =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_ModulationRate]);
            rate->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(rate);
            mSliders.add(rate);
            x = x + (slider_size * 2 );
            
            TTParameterSlider* depth =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_ModulationDepth]);
            depth->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(depth);
            mSliders.add(depth);
            x = x + (slider_size * 2 );
            
            TTParameterSlider* wetdry =
            new TTParameterSlider(mProcessor->parameters, TTParameterID[tParameter_DelayWetDry]);
            wetdry->setBounds(x, y, slider_size, slider_size);
            addAndMakeVisible(wetdry);
            mSliders.add(wetdry);
            x = x + (slider_size * 2 );
            
            
        }break;
        
        default:
        case(tTTFxPanelStyle_TotalNumStyles): {
            // ferrou

            jassertfalse;
        }break;

    }
}
