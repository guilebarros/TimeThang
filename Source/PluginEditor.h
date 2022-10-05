#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class TimeThangAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TimeThangAudioProcessorEditor (TimeThangAudioProcessor&);
    ~TimeThangAudioProcessorEditor() override;

   
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    TimeThangAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimeThangAudioProcessorEditor)
};
