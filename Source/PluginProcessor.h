#pragma once

#include <JuceHeader.h>
#include "TTGain.h"
#include "TTDelay.h"
#include "TTLfo.h"

class TimeThangAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    TimeThangAudioProcessor();
    ~TimeThangAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    juce::AudioProcessorValueTreeState parameters;

private:
    /** internal function */
    void initializeDSP();
    
    /** internal function */
    void initializeParameters();
    
    std::unique_ptr<TTGain> mInputGain [2];
    std::unique_ptr<TTGain> mOutputGain [2];
    std::unique_ptr<TTDelay> mDelay [2];
    std::unique_ptr<TTLfo> mLfo [2];
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimeThangAudioProcessor)
};
