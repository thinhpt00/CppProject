#ifndef __TRIP__
#define __TRIP__

#include "transport.hpp"
#include "hotel.hpp"

class Trip{
private:
    Transport transportType;
    string startLocation, endLocation;
    Date fromDate, toDate;
    int numberOfPeople;
    Hotel place;
    float tripCost;
public:

};

#endif