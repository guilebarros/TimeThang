#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "TTParameters.h"

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
                       ),
       parameters(*this, nullptr)
#endif
{
    initializeParameters();
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

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        mInputGain[channel]->process(channelData,
                                getParameter(tParameter_InputGain),
                                channelData,
                                buffer.getNumSamples());
        
        float rate = (channel == 0) ? 0 : getParameter(tParameter_ModulationRate); // aplicando o rate apenas no canal esquerdo (0)
        
        mLfo[channel]->process(rate,
                               getParameter(tParameter_ModulationDepth),
                               buffer.getNumSamples());
        
        // delay with static values
        mDelay[channel]->process(channelData,
                                 getParameter(tParameter_DelayTime),
                                 getParameter(tParameter_DelayFeedback),
                                 getParameter(tParameter_DelayWetDry),
                                 mLfo[channel]->getBuffer(),
                                 channelData,
                                 buffer.getNumSamples());
        
        mOutputGain[channel]->process(channelData,
                                      getParameter(tParameter_OutputGain),
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
        mInputGain[i] = std::make_unique<TTGain>();
        mOutputGain[i] = std::make_unique<TTGain>();
        mDelay[i] = std::make_unique<TTDelay>();
        mLfo[i] = std::make_unique<TTLfo>();
    }
}

void TimeThangAudioProcessor::initializeParameters()
{
    for(int i = 0; i < tParameter_TotalNumParameters; i++)
    {
       parameters.createAndAddParameter(TTParameterID[i],
                                        TTParameterID[i],
                                        TTParameterID[i],
                                        juce::NormalisableRange<float>(0.0f, 1.0f),
                                        0.5f,
                                        nullptr,
                                        nullptr);
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TimeThangAudioProcessor();
}
