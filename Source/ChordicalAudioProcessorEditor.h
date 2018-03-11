#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ChordicalAudioProcessor.h"
#include <string.h>
//==============================================================================
class CommunicableWebBrowserComponent : public WebBrowserComponent
{
public:
    bool pageAboutToLoad (const String & newURL) override
    {
        printf("\n page about to load! %s \n", newURL.toRawUTF8());
        std::string url = newURL.toStdString();
        std::string::size_type nativeBridgeIndex = url.find( "native-bridge://data=", 0 );
        if(nativeBridgeIndex == std::string::npos){
            printf("initial page load \n");
            return true;
        }
        //get the params sent in the url. e.g. data=
        URL juceUrl(url);
        StringArray paramVals = juceUrl.getParameterValues();
        String dataString = paramVals[0];
        //convert the encoded data string into a json object
        juce::var dataJson = JSON::parse(dataString);
        if (this->uiDataCallbackFunc != nil){
            this->uiDataCallbackFunc(dataJson);
        }
        return false;
    }

    void registerUIDataCallbackFunc (std::function<void(juce::var)> callbackFunc){
        this->uiDataCallbackFunc = callbackFunc;
    }

private:
    std::function<void(juce::var)> uiDataCallbackFunc;
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
