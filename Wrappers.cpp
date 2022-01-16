#include "Wrappers.h"

ComputerWrapper::ComputerWrapper( Computer* ptr ) : pointerToComputer( ptr ) { }
ComputerWrapper::~ComputerWrapper() { delete pointerToComputer; pointerToComputer = nullptr; }

CarWrapper::CarWrapper( Car* ptr ) : pointerToCar( ptr ) { }
CarWrapper::~CarWrapper(){ delete pointerToCar; pointerToCar = nullptr; }

EngineWrapper::EngineWrapper( Car::Engine* ptr ) : pointerToEngine( ptr ) { }
EngineWrapper::~EngineWrapper(){ delete pointerToEngine; pointerToEngine = nullptr; }

SynthWrapper::SynthWrapper( Synth* ptr ) : pointerToSynth( ptr ) { }
SynthWrapper::~SynthWrapper(){ delete pointerToSynth; pointerToSynth = nullptr; }

MicrophoneWrapper::MicrophoneWrapper( Synth::Microphone* ptr ) : pointerToMicrophone( ptr ) { }
MicrophoneWrapper::~MicrophoneWrapper(){ delete pointerToMicrophone; pointerToMicrophone = nullptr; }

MusicianWrapper::MusicianWrapper( Musician* ptr ) : pointerToMusician( ptr ) { }
MusicianWrapper::~MusicianWrapper(){ delete pointerToMusician; pointerToMusician = nullptr; }

GarageWrapper::GarageWrapper( Garage* ptr ) : pointerToGarage( ptr ) { }
GarageWrapper::~GarageWrapper(){ delete pointerToGarage; pointerToGarage = nullptr; }
