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
};
