#include "TTParameterSlider.h"

TTParameterSlider::TTParameterSlider(juce::AudioProcessorValueTreeState& stateToControl, const juce::String& parameterID)
: juce::Slider(parameterID)

{
    setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
    setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
    setRange(0.0f, 1.0f, 0.001f);
    
    mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(stateToControl, parameterID, *this);
}
TTParameterSlider::~TTParameterSlider()
{
    
}



