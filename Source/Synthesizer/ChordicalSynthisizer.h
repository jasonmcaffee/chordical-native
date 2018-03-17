#pragma once
#include "../SynthesizerSound/Sound.h"
#include "../SynthesizerVoice/SineWaveVoice.h"
class ChordicalSynthesizer : public Synthesiser{
public:
    ChordicalSynthesizer(){
      const int numVoices = 8;
      // Add some voices...
      for (int i = numVoices; --i >= 0;)
        this->addVoice (new SineWaveVoice());
      this->addSound(new Sound());
    }

    /**
     * We want to broadcast a signal so envelopes, effects, etc know when a note is started
     * @param midiChannel
     * @param midiNoteNumber
     * @param velocity
     */
    void noteOn (int midiChannel, int midiNoteNumber, float velocity){
      printf("ChordicalSynthesizer noteOn called \n");
      Synthesiser::noteOn(midiChannel, midiNoteNumber, velocity);
    }

    void noteOff (int midiChannel, int midiNoteNumber, float velocity, bool allowTailOff){
      Synthesiser::noteOff(midiChannel midiNoteNumber, velocity, allowTailOff);
    }
};
