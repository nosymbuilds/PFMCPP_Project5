/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of paamountOfRAMeters
            give some of those paamountOfRAMeters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
        
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) add 2 member functions to each of these 2 new types.
       These member functions should make use of the member variables. 
       Maybe interact with their properties or call their member functions.
       The purpose is to demonstrate that you know how to use a class's member variables and member functions when it is a member of another class.
 
 7) use at least 2 instances of each of your UDTs in main. 
       - call every member function of your UDTs to make sure they work as expected and don't produce warnings.
       - add some std::cout statements in main() that use your UDT's member variables.
       you have 5 UDTs and 2 nested UDTs, so there should be at minimum 14 UDTs declared in main(), as well as 14 * 3 function calls happening.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
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
    std::cout << "good to go!" << std::endl;
}
