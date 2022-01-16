#pragma once
#include "LeakedObjectDetector.h"

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

    JUCE_LEAK_DETECTOR(Computer)
};
