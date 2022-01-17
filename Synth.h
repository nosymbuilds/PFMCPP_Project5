#pragma once
#include "LeakedObjectDetector.h"

struct Synth
{
    std::string name;
    int presets;
    int filters;
    int outputs = 2;
    int effectsLoaded;

    Synth( std::string name_ );
    ~Synth();
    void outputMidi( int midiOutput = 1 );
    void loadPresets( std::string presetBankName = "All" );
    void loadEffects( int numOfEffects );
    void print();

    struct Microphone
    {
        std::string name;
        std::string type;
        std::string pattern;
        bool stereo = false;
        bool lowCut = true;

        Microphone( std::string name_ );
        ~Microphone();
        void record();
        void pitch( int semitones  );
        void power( bool on );
        void print();

        JUCE_LEAK_DETECTOR(Microphone)
    };

    JUCE_LEAK_DETECTOR(Synth)
};
