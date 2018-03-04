#include "ChordicalAudioProcessor.h"
#include "ChordicalAudioProcessorEditor.h"
#include <stdio.h>
#include "Waves/Sine.h"
//==============================================================================
ChordicalAudioProcessorEditor::ChordicalAudioProcessorEditor (ChordicalAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), midiKeyboard (p.keyboardState, MidiKeyboardComponent::horizontalKeyboard)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    addAndMakeVisible (&playButton);
    playButton.setButtonText ("Play");
    playButton.addListener (this);

    midiKeyboard.setVisible(true);
    addAndMakeVisible (midiKeyboard);
    setSize (700, 700);
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
