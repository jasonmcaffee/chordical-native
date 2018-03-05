#include "ChordicalAudioProcessor.h"
#include "ChordicalAudioProcessorEditor.h"
#include <stdio.h>
#include "Waves/Sine.h"
#include "BinaryData/UI.c"

//==============================================================================
ChordicalAudioProcessorEditor::ChordicalAudioProcessorEditor (ChordicalAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), midiKeyboard (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard),
      webBrowserComponent()
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    printf("Starting editor.. ");
    printf("%s", index_html);
    setSize (700, 700);

    midiKeyboard.setVisible(true);
    midiKeyboard.setBounds(0, 100, 700, 100);
    addAndMakeVisible (midiKeyboard);

    webBrowserComponent.setVisible(true);
    webBrowserComponent.setBounds(0, 200, 700, 500);
    addAndMakeVisible(webBrowserComponent);
    webBrowserComponent.goToURL("file://UI/index.html");
    repaint();

}

ChordicalAudioProcessorEditor::~ChordicalAudioProcessorEditor()
{
}

//==============================================================================
void ChordicalAudioProcessorEditor::paint (Graphics& g)
{
//    printf("ChordicalAudioProcessorEditor paint called \n");

    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//
//    g.setColour (Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World MEEEE!", getLocalBounds(), Justification::centred, 1);

}

void ChordicalAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void ChordicalAudioProcessorEditor::buttonClicked (Button* button)
{
    printf("playbutton clicked");
}
