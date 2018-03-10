#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ChordicalAudioProcessor.h"

//==============================================================================
class CommunicableWebBrowserComponent : public WebBrowserComponent
{
public:
    bool pageAboutToLoad (const String & newURL) override
    {
        printf("\n page about to load! %s \n", newURL.toRawUTF8());
        return true;
    }
};
/**
*/
class ChordicalAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Button::Listener
{
public:
    ChordicalAudioProcessorEditor (ChordicalAudioProcessor&);
    ~ChordicalAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button* b) override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ChordicalAudioProcessor& processor;
    TextButton playButton;
    MidiKeyboardComponent midiKeyboard;
    CommunicableWebBrowserComponent webBrowserComponent;
    void updateCurrentTimeInfoFromHost();
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ChordicalAudioProcessorEditor)
};
