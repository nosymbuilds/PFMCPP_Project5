#include "Musician.h"

Musician::Musician( std::string name_ ) : name(name_)
{
    std::cout << name << " entered the studio." << std::endl;
}

Musician::~Musician()
{
    std::cout << name << " left the studio." << std::endl;
}

void Musician::playSynth( int effects, std::string presets )
{
    synth.loadEffects( effects );
    synth.loadPresets( presets );
    std::cout << name << " plays the synth" << std::endl;
}

void Musician::recordMidi( int channel )
{
    synth.outputMidi( channel );
}

void Musician::print( )
{
       std::cout << this->name << "'s computer has " << this->computer.amountOfRAM << "GB of RAM" << std::endl;
}
