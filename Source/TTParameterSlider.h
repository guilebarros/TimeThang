#pragma once
#include<JuceHeader.h>

class TTParameterSlider
: public juce::Slider

{
    
public:
    
    TTParameterSlider(juce::AudioProcessorValueTreeState& stateToControl, const juce::String& parameterID);
    ~TTParameterSlider();
    
private:
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TTParameterSlider);
};

