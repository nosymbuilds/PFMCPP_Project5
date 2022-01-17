#include "Synth.h"

Synth::Synth( std::string name_ ) : name(name_), presets(100), filters(3), effectsLoaded(0)
{
    std::cout << "Synth object constructed" << std::endl;
}

Synth::~Synth()
{
    std::cout << "Synth object destructed" << std::endl;
}

Synth::Microphone::Microphone( std::string name_) : name(name_), type("dynamic"), pattern("omnidirectional")
{
    std::cout << "Microphone object constructed" << std::endl;
}

Synth::Microphone::~Microphone()
{
    std::cout << "Microphone object destructed" << std::endl;
}

void Synth::outputMidi(int midiOutput)
{
    std::cout << "Midi data is sent to midi output " << midiOutput << " on the " << name << " synth." << std::endl;
}

void Synth::loadPresets(std::string presetBankName)
{
    std::cout << presetBankName << " presets have been loaded onto the " << name << " synth." << std::endl;
}

void Synth::loadEffects(int numOfEffects)
{   
    if( numOfEffects == 0 )
    {
        std::cout << "No effects loaded onto the " << name << " synth" << std::endl;
    }
    else
    {
        for(int i = 0; i <= numOfEffects - 1 ; ++i)
        {
            std::cout << "Effect " << i + 1 << " loaded" << std::endl;
            ++effectsLoaded;
        }   
        std::cout << "All requested effects have been loaded onto the " << name << " synth" << std::endl;
    }

}

void Synth::Microphone::record()
{
    std::cout << "The " << name << " mic is recording..." << std::endl;
}

void Synth::Microphone::pitch( int semitones )
{
    if( semitones > 0 )
        std::cout << "Your voice has been pitched " << semitones << " semitone's up " << std::endl;
    else
        std::cout << "Your voice has been pitched " << semitones << " semitone's down " <<  std::endl;
}

void Synth::Microphone::power( bool on )
{
    if( on )
        std::cout << "The " << name << " mic has been turned on" << std::endl;
    else
        std::cout << "The " << name << " mic has been turned off" << std::endl;
}

void Synth::print()
{
    std::cout << "The " << this->name << " has " << this->presets << " presets." << std::endl;
}

void Synth::Microphone::print()
{
    std::cout << "The " << this->name << " is a " << this->type << " type mic." << std::endl;
}
