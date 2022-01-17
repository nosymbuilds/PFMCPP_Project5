#pragma once
#include "LeakedObjectDetector.h"
#include "Car.h"

struct Garage
{
    Car car { "E46", "BMW", 8000.02f };
    Car::Engine engine { "M10", 2, 8, 1 } ;

    Garage();
    ~Garage();
    void getInformation( std::string item );
    void clean( std::string item);
    void print();

    JUCE_LEAK_DETECTOR(Garage)
};
