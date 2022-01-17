/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */

#include <iostream>

#include "Wrappers.h"
#include "Computer.h"
#include "Car.h"
#include "Synth.h"
#include "Musician.h"
#include "Garage.h"

int main()
{
    // UDT 1
    ComputerWrapper mac( new Computer(16, "macbook", 2019) );
    ComputerWrapper windows( new Computer(8, "notebook", 2022) );
    mac.pointerToComputer->checkWarranty( mac.pointerToComputer->year );
    mac.pointerToComputer->upgrade( true, 32, 5.6 );
    mac.pointerToComputer->storeData( 60.9f );
    windows.pointerToComputer->checkWarranty( windows.pointerToComputer->year );
    windows.pointerToComputer->upgrade( false, 16, 4.2);
    windows.pointerToComputer->storeData( 1.246f );
    std::cout << std::endl;
    
    // UDT 2
    CarWrapper sports( new Car( "M5", "BMW", 10000.43f ));
    CarWrapper offRoad( new Car( "Discovery", "Land Rover", 67343.12f ));
    sports.pointerToCar->drive( 32.4f );
    sports.pointerToCar->service();
    sports.pointerToCar->scrap( "cash" );   
    offRoad.pointerToCar->drive( 1000.23f );
    offRoad.pointerToCar->service();
    offRoad.pointerToCar->safetyRating = 9;
    offRoad.pointerToCar->scrap();

    EngineWrapper bmwEngine( new Car::Engine( "S14", 4, 16, 2 ) );
    EngineWrapper landRoverEngine( new Car::Engine( "Td5", 2, 12, 1 ) );
    bmwEngine.pointerToEngine->firePiston();
    bmwEngine.pointerToEngine->lubricateEngine( 0.2 );
    bmwEngine.pointerToEngine->produceEnergy();
    landRoverEngine.pointerToEngine->firePiston();
    landRoverEngine.pointerToEngine->lubricateEngine( 4.0 );
    landRoverEngine.pointerToEngine->produceEnergy();
    std::cout << std::endl;

    // UDT 3
    SynthWrapper roland( new Synth( "Roland 808" ));
    SynthWrapper yamaha( new Synth( "Yamaha DX7" ));
    roland.pointerToSynth->outputMidi();
    roland.pointerToSynth->loadPresets();
    roland.pointerToSynth->loadEffects( 2 );
    yamaha.pointerToSynth->outputMidi( 2 );
    yamaha.pointerToSynth->loadPresets( "String" );
    yamaha.pointerToSynth->loadEffects( 0 );  

    MicrophoneWrapper rolandMic( new Synth::Microphone( "Roland DR-50" ) );
    MicrophoneWrapper yamahaMic( new Synth::Microphone( "Yamaha YA-1" ) );
    rolandMic.pointerToMicrophone->power( true );
    rolandMic.pointerToMicrophone->record();
    rolandMic.pointerToMicrophone->pitch( -3 );
    yamahaMic.pointerToMicrophone->power( false );
    yamahaMic.pointerToMicrophone->record();
    yamahaMic.pointerToMicrophone->pitch( 6 );
    std::cout << std::endl;
    
    // UDT 4
    MusicianWrapper brianEno( new Musician( "Brian Eno" ) );
    MusicianWrapper kateBush( new Musician( "Kate Bush" ) );
    brianEno.pointerToMusician->recordMidi( 2 );
    brianEno.pointerToMusician->playSynth( 2 , "Pad" );
    kateBush.pointerToMusician->recordMidi( 1 );
    kateBush.pointerToMusician->playSynth( 0 , "Drum" );
    std::cout << std::endl;

    // UDT 5
    GarageWrapper myGarage( new Garage() );
    GarageWrapper neighboursGarage( new Garage() );
    myGarage.pointerToGarage->getInformation( "car" );
    myGarage.pointerToGarage->getInformation( "engine" );
    myGarage.pointerToGarage->clean( "boat" );
    neighboursGarage.pointerToGarage->getInformation( "time machine" );
    neighboursGarage.pointerToGarage->getInformation( "pickle rick" );
    neighboursGarage.pointerToGarage->clean( "engine" );
    std::cout << std::endl;

    // this->
    std::cout << "The " << roland.pointerToSynth->name << " has " << roland.pointerToSynth->presets << " presets." << std::endl;
    roland.pointerToSynth->print();

    std::cout << "The " << rolandMic.pointerToMicrophone->name << " is a " << rolandMic.pointerToMicrophone->type << " type mic." << std::endl;
    rolandMic.pointerToMicrophone->print();

    std::cout << kateBush.pointerToMusician->name << "'s computer has " << kateBush.pointerToMusician->computer.amountOfRAM << "GB of RAM" << std::endl;
    kateBush.pointerToMusician->print();

    std::cout << "The safety rating of my " << myGarage.pointerToGarage->car.name << " is " << myGarage.pointerToGarage->car.safetyRating << std::endl;
    myGarage.pointerToGarage->print();

    std::cout << "The " << landRoverEngine.pointerToEngine->name << " engine has " << landRoverEngine.pointerToEngine->pistons << " pistons." << std::endl;
    landRoverEngine.pointerToEngine->print();

    std::cout << "The " << offRoad.pointerToCar->name << " is manufactured by " << offRoad.pointerToCar->manufacturer << std::endl;
    offRoad.pointerToCar->print();

    std::cout << "The name of this computer is " << mac.pointerToComputer->name << std::endl;
    mac.pointerToComputer->print();

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
