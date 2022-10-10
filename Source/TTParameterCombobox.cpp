#include "TTParameterCombobox.h"


TTParameterComboBox::TTParameterComboBox(juce::AudioProcessorValueTreeState& stateToControl, const juce::String& parameterID)
: juce::ComboBox(parameterID)

{
    
    mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(stateToControl, parameterID, *this);
    
}

TTParameterComboBox::~TTParameterComboBox()
{
    
}
