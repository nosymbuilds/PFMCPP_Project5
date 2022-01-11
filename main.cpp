/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
/*
 UDT 1:
 */
struct Computer
{
    int amountOfRAM;
    std::string name;
    int year;
    double processorPower = 2.2;
    float availableStorage = 106.73f;

    Computer( int amountOfRAM_, std::string name_, int year_ );
    ~Computer();
    void upgrade( bool freeUpgrade, int amountOfRAM, double processorPower );
    void storeData( float sizeOfData );
    void checkWarranty( int yearProduced );
    void print();
};

Computer::Computer( int amountOfRAM_, std::string name_, int year_ ) : amountOfRAM(amountOfRAM_), name(name_), year(year_)
{
    std::cout << "Computer object constructed" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer object destructed" << std::endl;
}

void Computer::upgrade( bool freeUpgrade = true, int newamountOfRAM = 64, double newprocessorPower = 3.5 )
{
    std::cout << name << " stats before the upgrade - " << "amountOfRAM: " << amountOfRAM << "GB" << " / processorPower: " << processorPower << "Mhz" << std::endl;
    amountOfRAM = newamountOfRAM;
    processorPower = newprocessorPower;
    std::cout << name << " stats after the upgrade - " << "amountOfRAM: " << amountOfRAM << "GB" << " / processorPower: " << processorPower << "Mhz" << std::endl;

    if( freeUpgrade )
        std::cout << "The upgrades are complete. As you qualify for free upgrades you have not been charged" << std::endl;
    else
        std::cout << "The upgrades are complete. You have been charged £49.99 for labour." << std::endl;
}

void Computer::storeData( float sizeOfData )
{   
    std::cout << "Available storage on " << name << " before data transfer: " << availableStorage << "MB" << std::endl;

    if( availableStorage > sizeOfData )
        availableStorage -= sizeOfData;
    else
        std::cout << "There is not enough free space to store the data." << std::endl;

    std::cout << "Available storage on " << name << " after data transfer: " << availableStorage << "MB" << std::endl;
}

void Computer::checkWarranty( int yearProduced )
{
    if( yearProduced > 2019 )
        std::cout << "This " << name << " is currently under warranty." << std::endl;
    else
        std::cout << "This " << name << " is not currently under warranty." << std::endl;
}

void Computer::print()
{
    std::cout << "The name of this computer is " << this->name << std::endl;
}

/*
 UDT 2:
 */
struct Car
{
    std::string name;
    std::string manufacturer;
    float mileage;
    int safetyRating = 5;
    double fuelCapacity = 8.6;

    Car( std::string name_, std::string manufacturer_, float mileage_  );
    ~Car();
    void drive( float distance );
    void service();
    void scrap( std::string exchangeType = "credit" );
    void print();
 
    struct Engine
    {
        std::string name;
        int pistons;
        int valves;
        int oilPans;
        std::string engineBlockType = "combustion";

        Engine( std::string name_, int pistons_, int valves_, int oilPans_ );
        ~Engine();
        void produceEnergy();
        void lubricateEngine(double availableOilInLitres = 0.9);
        void firePiston();
        void print();
    };
};

Car::Car( std::string name_, std::string manufacturer_, float mileage_ ) : name(name_), manufacturer(manufacturer_), mileage(mileage_)
{
    std::cout << "Car object constructed" << std::endl;
}

Car::~Car()
{
    std::cout << "Car object destructed" << std::endl;
}

Car::Engine::Engine( std::string name_, int pistons_, int valves_, int oilPans_ ) : name(name_), pistons(pistons_), valves(valves_), oilPans(oilPans_) 
{
    std::cout << "Engine constructed" << std::endl;
}

Car::Engine::~Engine()
{
    std::cout << "Engine destructed" << std::endl;
}

void Car::drive( float distance )
{
    std::cout << "Mileage of " << name << " before journey " << mileage << "km" <<  std::endl;

    float newTotalMileage = mileage + distance;

    while( mileage < newTotalMileage )
        mileage += distance / 10;

    std::cout << "Mileage of " << name << " after journey " << mileage << "km" << std::endl << std::endl;
}

void Car::service()
{
    std::cout << "The " << manufacturer << " team have completed the service of your car." << std::endl;
}

void Car::scrap( std::string exchangeType )
{
    int crushes = 0;
    while( safetyRating > 0 )
    {
        --safetyRating;
        ++crushes;
    }

    std::cout << "The scrapping process was completed. It took the crusher " << crushes << " attempts to completley crush your " << manufacturer << " " << name << std::endl;

    if( exchangeType == "cash" )
        std::cout << "As requested, you received cash for scrapping your car" << std::endl;
    else
        std::cout << "As requested, you received credit for scrapping your car" << std::endl;
}

void Car::Engine::produceEnergy()
{
    int energy = pistons * valves;
    std::cout << "The " << name << " " << engineBlockType << " engine produces " << energy << "btu of energy." << std::endl;
}

void Car::Engine::lubricateEngine(double availableOilInLitres)
{
    if (availableOilInLitres <= 0.3)
    {
        std::cout << "There is not enough oil to lubcricate the engine efficiently, please add more oil." << std::endl;
    }
    else 
    {
        double newOilLevel = availableOilInLitres - 0.1;
        std::cout << "The engine is lubricated with oil. There is " << newOilLevel << " litres of oil available after lubricating the engine." << std::endl;    
    }
}

void Car::Engine::firePiston()
{
    int i = 0;
    while(i < pistons)
    {  
        std::cout << "Firing " << name << " piston no." << i + 1 << std::endl;
        ++i;
    }

    std::cout << "All pistons firing!" << std::endl;
}

void Car::print()
{
    std::cout << "The " << this->name << " is manufactured by " << this->manufacturer << std::endl;
}

void Car::Engine::print()
{
    std::cout << "The " << this->name << " engine has " << this->pistons << " pistons." << std::endl;
}

/*
 UDT 3:
 */
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
    };
};

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

/*
 new UDT 4:
 */
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
};

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

/*
 new UDT 5:
 */
struct Garage
{
    Car car { "E46", "BMW", 8000.02f };
    Car::Engine engine { "M10", 2, 8, 1 } ;

    Garage();
    ~Garage();
    void getInformation( std::string item );
    void clean( std::string item);
    void print();
};

Garage::Garage()
{
    std::cout << "You opened the garage door" << std::endl;
}

Garage::~Garage()
{
    std::cout << "You closed the garage door" << std::endl;
}

void Garage:: getInformation( std::string item )
{
    if( item == "car")
    {
        std::cout << "**" << car.name << " details**" << std::endl;
        std::cout << "Manufacturer: " << car.manufacturer << std::endl;
        std::cout << "Mileage: " << car.mileage << std::endl;
        std::cout << "Safety Rating: " << car.safetyRating << std::endl;
    }
    else if( item == "engine" )
    {
        std::cout << "**" << engine.name << " details**" << std::endl;
        std::cout << "Pistons: " << engine.pistons << std::endl;
        std::cout << "Valves: " << engine.valves << std::endl;
        std::cout << "Block Type: " << engine.engineBlockType << std::endl;
    }
    else
    {
        std::cout << "You dont have a " << item << " in your garage" << std::endl;
    }
}

void Garage::clean( std::string item )
{
    if( item == "car")
    {
        std::cout << car.name << " looked a little dirty so you gave it a clean" << std::endl;
    }
    else if( item == "engine" )
    {
        std::cout << car.name << " looked kinda dusty so you gave it a polish" << std::endl;
    }
    else
    {
        std::cout << "You dont have a " << item << " in your garage" << std::endl;
    }
}

void Garage::print( )
{
   std::cout << "The safety rating of my " << this->car.name << " is " << this->car.safetyRating << std::endl;
}

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
int main()
{
    // UDT 1
    Computer mac { 16, "macbook", 2019 };
    Computer windows { 8, "notebook", 2022} ;
    mac.checkWarranty( mac.year );
    mac.upgrade( true, 32, 5.6 );
    mac.storeData( 60.9f );
    windows.checkWarranty( windows.year );
    windows.upgrade( false, 16, 4.2);
    windows.storeData( 1.246f );
    std::cout << std::endl;
    
    // UDT 2
    Car sports { "M5", "BMW", 10000.43f };
    Car offRoad { "Discovery", "Land Rover", 67343.12f } ;
    sports.drive( 32.4f );
    sports.service();
    sports.scrap( "cash" );   
    offRoad.drive( 1000.23f );
    offRoad.service();
    offRoad.safetyRating = 9;
    offRoad.scrap();
    
    Car::Engine bmwEngine { "S14", 4, 16, 2 } ;
    Car::Engine landRoverEngine { "Td5", 2, 12, 1 } ;
    bmwEngine.firePiston();
    bmwEngine.lubricateEngine( 0.2 );
    bmwEngine.produceEnergy();
    landRoverEngine.firePiston();
    landRoverEngine.lubricateEngine( 4.0 );
    landRoverEngine.produceEnergy();
    std::cout << std::endl;

    // UDT 3
    Synth roland { "Roland 808" };
    Synth yamaha { "Yamaha DX7" };
    roland.outputMidi();
    roland.loadPresets();
    roland.loadEffects( 2 );
    yamaha.outputMidi( 2 );
    yamaha.loadPresets( "String" );
    yamaha.loadEffects( 0 );  

    
    Synth::Microphone rolandMic { "Roland DR-50" };
    Synth::Microphone yamahaMic { "Roland YA-1" };
    rolandMic.power( true );
    rolandMic.record();
    rolandMic.pitch( -3 );
    yamahaMic.power( false );
    yamahaMic.record();
    yamahaMic.pitch( 6 );
    std::cout << std::endl;
    
    // UDT 4
    Musician brianEno { "Brian Eno" };
    Musician kateBush { "Kate Bush" };
    brianEno.recordMidi( 2 );
    brianEno.playSynth( 2 , "Pad" );
    kateBush.recordMidi( 1 );
    kateBush.playSynth( 0 , "Drum" );
    std::cout << std::endl;

    // UDT 5
    Garage myGarage;
    Garage neighboursGarage;
    myGarage.getInformation( "car" );
    myGarage.getInformation( "engine" );
    myGarage.clean( "boat" );
    neighboursGarage.getInformation( "time machine" );
    neighboursGarage.getInformation( "pickle rick" );
    neighboursGarage.clean( "engine" );
    std::cout << std::endl;

    // this->
    std::cout << "The " << roland.name << " has " << roland.presets << " presets." << std::endl;
    roland.print();

    std::cout << "The " << rolandMic.name << " is a " << rolandMic.type << " type mic." << std::endl;
    rolandMic.print();

    std::cout << kateBush.name << "'s computer has " << kateBush.computer.amountOfRAM << "GB of RAM" << std::endl;
    kateBush.print();

    std::cout << "The safety rating of my " << myGarage.car.name << " is " << myGarage.car.safetyRating << std::endl;
    myGarage.print();

    std::cout << "The " << landRoverEngine.name << " engine has " << landRoverEngine.pistons << " pistons." << std::endl;
    landRoverEngine.print();

    std::cout << "The " << offRoad.name << " is manufactured by " << offRoad.manufacturer << std::endl;
    offRoad.print();

    std::cout << "The name of this computer is " << mac.name << std::endl;
    mac.print();

    std::cout << std::endl;
    std::cout << "good to go!" << std::endl;
}
