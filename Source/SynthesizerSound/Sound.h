#pragma once
class Sound : public SynthesiserSound
{
public:
    Sound() {}
    bool appliesToNote (int /*midiNoteNumber*/) override    { return true; }
    bool appliesToChannel (int /*midiChannel*/) override    { return true; }
};