#pragma once
#include "../SynthesizerSound/Sound.h"
#include "../SynthesizerVoice/SineWaveVoice.h"
#include "../Core/EventBus.h"

class ChordicalSynthesizer : public Synthesiser{
public:
    ChordicalSynthesizer(){
      const int numVoices = 8;
      // Add some voices...
      for (int i = numVoices; --i >= 0;)
        this->addVoice (new SineWaveVoice());
      this->addSound(new Sound());

      eventBus.registerCallback(eventBus.events.NotePressed, [this](EventData data){
        printf("ChordicalSynthesizer notePressed event received %d \n", numVoices);
      });
    }

    /**
     * We want to broadcast a signal so envelopes, effects, etc know when a note is started
     * @param midiChannel
     * @param midiNoteNumber
     * @param velocity
     */
    void noteOn (int midiChannel, int midiNoteNumber, float velocity){
      printf("ChordicalSynthesizer noteOn called \n");
      NotePressedEventData e = NotePressedEventData("c#");
      eventBus.trigger(eventBus.events.NotePressed, e);
//      eventBus::trigger(data);
      Synthesiser::noteOn(midiChannel, midiNoteNumber, velocity);
    }

    void noteOff (int midiChannel, int midiNoteNumber, float velocity, bool allowTailOff){
      Synthesiser::noteOff(midiChannel, midiNoteNumber, velocity, allowTailOff);
    }
};
