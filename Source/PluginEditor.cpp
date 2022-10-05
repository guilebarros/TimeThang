#include "PluginProcessor.h"
#include "PluginEditor.h"


TimeThangAudioProcessorEditor::TimeThangAudioProcessorEditor (TimeThangAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{

    setSize (400, 300);
}

TimeThangAudioProcessorEditor::~TimeThangAudioProcessorEditor()
{
}

void TimeThangAudioProcessorEditor::paint (juce::Graphics& g)
{
   
    g.fillAll (juce::Colours::black);
}

void TimeThangAudioProcessorEditor::resized()
{

}
