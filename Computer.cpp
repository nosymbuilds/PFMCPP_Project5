#include "Computer.h"

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
