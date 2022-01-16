#include "Car.h"

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
