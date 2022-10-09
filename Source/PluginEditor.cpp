#include "PluginProcessor.h"
#include "PluginEditor.h"


TimeThangAudioProcessorEditor::TimeThangAudioProcessorEditor (TimeThangAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    

    setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
    
    mMainPanel = std::make_unique<TTMainPanel>(&audioProcessor);
    
    mMainPanel->setBounds(0,0,MAIN_PANEL_WIDTH,MAIN_PANEL_HEIGHT);
    
    mMainPanel->setName("example");
    
    addAndMakeVisible(mMainPanel.get());
    
    
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
