#include "Garage.h"

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
