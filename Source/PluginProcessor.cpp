#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TimeThangAudioProcessor::TimeThangAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    initializeDSP();
}

TimeThangAudioProcessor::~TimeThangAudioProcessor()
{
}

//==============================================================================
const juce::String TimeThangAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TimeThangAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TimeThangAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TimeThangAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TimeThangAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TimeThangAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TimeThangAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TimeThangAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TimeThangAudioProcessor::getProgramName (int index)
{
    return {};
}

void TimeThangAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TimeThangAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
    for(int i = 0; i < 2; i++)
    {
        mDelay[i]->setSampleRate(sampleRate);
        mLfo[i]->setSampleRate(sampleRate);
    }
    
}

void TimeThangAudioProcessor::releaseResources()
{
    for(int i = 0; i < 2; i++)
    {
        mDelay[i]->reset();
        mLfo[i]->reset();
    }

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TimeThangAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TimeThangAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

  
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        mGain[channel]->process(channelData,
                                0.5,
                                channelData,
                                buffer.getNumSamples());
        
        mLfo[channel]->process(0.25, 0.5, buffer.getNumSamples());
        
        // delay with static values
        mDelay[channel]->process(channelData,
                                 0.25,
                                 0.5,
                                 0.35,
                                 mLfo[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
    }
}

//==============================================================================
bool TimeThangAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TimeThangAudioProcessor::createEditor()
{
    return new TimeThangAudioProcessorEditor (*this);
}

//==============================================================================
void TimeThangAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TimeThangAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

void TimeThangAudioProcessor::initializeDSP()
{
    for(int i = 0; i < 2; i++)
    {
        mGain[i] = std::make_unique<TTGain>();
        mDelay[i] = std::make_unique<TTDelay>();
        mLfo[i] = std::make_unique<TTLfo>();
    }
}


//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TimeThangAudioProcessor();
}
