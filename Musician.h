#pragma once
#include "LeakedObjectDetector.h"
#include "Synth.h"
#include "Computer.h"

struct Musician
{
    std::string name;
    Synth synth { "Juno 106" };
    Synth::Microphone synthMic { "DR-80C" };
    Computer computer { 8, "macbook", 2015 };

    Musician( std::string name_);
    ~Musician();
    void playSynth( int effects, std::string presets );
    void recordMidi( int channel );
    void print();

    JUCE_LEAK_DETECTOR(Musician)
};
