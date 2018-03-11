#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "ChordicalAudioProcessor.h"
#include <string.h>
//==============================================================================
typedef void (* UIDataCallbackFunc)(std::string dataString);
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

        URL juceUrl(url);
        StringArray paramVals = juceUrl.getParameterValues();
        String dataString = paramVals[0];
        juce::var dataJson = JSON::parse(dataString);
        printf("json test prop is: %s \n", dataJson["test"].toString().toRawUTF8());
        if (this->uiDataCallbackFunc != nil){
            this->uiDataCallbackFunc(dataString.toStdString());
        }
        return false;
    }
    void registerUIDataCallbackFunc (UIDataCallbackFunc callbackFunc){
        this->uiDataCallbackFunc = callbackFunc;
    }

private:
    UIDataCallbackFunc uiDataCallbackFunc;
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
