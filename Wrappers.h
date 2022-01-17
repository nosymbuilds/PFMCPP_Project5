#pragma once

#include "Car.h"
#include "Synth.h"
struct Computer;
struct Car;
struct Synth;
struct Musician;
struct Garage;

struct ComputerWrapper
{
    ComputerWrapper( Computer* ptr );
    ~ComputerWrapper();
    Computer* pointerToComputer = nullptr;
};

struct CarWrapper
{
    CarWrapper( Car* ptr );
    ~CarWrapper();
    Car* pointerToCar = nullptr; 
};

struct EngineWrapper
{
    EngineWrapper( Car::Engine* ptr ); //FIXME: include the file that this nested type is defined in
    ~EngineWrapper();
    Car::Engine* pointerToEngine = nullptr; 
};

struct SynthWrapper
{
    SynthWrapper( Synth* ptr );
    ~SynthWrapper();
    Synth* pointerToSynth = nullptr; 
};

struct MicrophoneWrapper
{
    MicrophoneWrapper( Synth::Microphone* ptr ); //FIXME: include the file that this nested type is defined in
    ~MicrophoneWrapper();
    Synth::Microphone* pointerToMicrophone = nullptr; 
};

struct MusicianWrapper
{
    MusicianWrapper( Musician* ptr );
    ~MusicianWrapper();
    Musician* pointerToMusician = nullptr; 
};

struct GarageWrapper
{
    GarageWrapper( Garage* ptr );
    ~GarageWrapper();
    Garage* pointerToGarage = nullptr; 
};
