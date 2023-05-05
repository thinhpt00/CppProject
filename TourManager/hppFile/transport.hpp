#ifndef __TRANSPORT__
#define __TRANSPORT__

#include "date.hpp"


class Transport{
protected:
    string transportName;
    string transportBrand;
    Date departureDay;
    string departurePlace;
    string destination;
    float ticketPrice;
public:
    
};

class Plane : public Transport{

};

class Car : public Transport{
    
};
#endif
