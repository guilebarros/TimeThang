#pragma once
#include <JuceHeader.h>


class TTParameterComboBox
: public juce::ComboBox

{
    
public:
    
    TTParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl, const juce::String& parameterID);
    ~TTParameterComboBox();
    
private:
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TTParameterComboBox);
    
};
