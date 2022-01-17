#pragma once
#include "LeakedObjectDetector.h"

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

        JUCE_LEAK_DETECTOR(Engine)
    };

    JUCE_LEAK_DETECTOR(Car)
};
