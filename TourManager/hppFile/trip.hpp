#ifndef __TRIP__
#define __TRIP__

#include "transport.hpp"
#include "hotel.hpp"
#include <algorithm>

class Trip{
private:
    Transport transportType;
    Hotel place;
    string fromDate, toDate;
    string startLocation, endLocation;
    int numberOfPeople;
    float tripCost;
public:
    void setTransportType(Transport type){transportType = type;}
    void setPlace(Hotel type){place = type;}
    void setFromDate(string type){fromDate = type;}
    void setToDate(string type){toDate = type;}
    void setStartLocation(string type){startLocation = type;}
    void setEndLocation(string type){endLocation = type;}
    void setNumberOfPeople(int type){numberOfPeople = type;}
    void setTripCost(float cost){tripCost = cost;}

    Transport getTransportType(){return transportType;}
    Hotel getPlace(){return place;}
    string getFromDate(){return fromDate;}
    string getToDate(){return toDate;}
    string getStartLocation(){return startLocation;}
    string getEndLocation(){return endLocation;}
    int getNumberOfPeople(){return numberOfPeople;}
    float getTripCost(){return tripCost;}

    friend bool operator < (Trip& trip1,Trip& trip2){
        return (trip1.tripCost < trip2.tripCost) ? true : false;
    }
    friend bool operator > (Trip& trip1,Trip& trip2){
        return (trip1.tripCost > trip2.tripCost) ? true : false;
    }

    void printTrip(){
        cout << "\n\n----------Trip Information----------";
        cout << "\n" << startLocation << " to " << endLocation << " from " << fromDate << " to " << toDate << endl;
        transportType.printTransport();
        place.printHotel();
        cout << "Number of people: " << numberOfPeople;
        cout <<"\n\t-> Trip cost: " << tripCost;
    }
};

#endif