#ifndef __TRIP__
#define __TRIP__

// #include "Header.hpp"
#include "transport.hpp"
#include "hotel.hpp"
// #include <algorithm>
// #include <vector>

class Trip{
private:
    vector<Transport> transportType;
    vector<Hotel> place;
    string fromDate, toDate;
    string startLocation, endLocation;
    int numberOfPeople;
    float tripCost;
public:
    void setTransportType(vector<Transport> type){transportType = type;}
    void setPlace(vector<Hotel> type){place = type;}
    void setFromDate(string type){fromDate = type;}
    void setToDate(string type){toDate = type;}
    void setStartLocation(string type){startLocation = type;}
    void setEndLocation(string type){endLocation = type;}
    void setNumberOfPeople(int type){numberOfPeople = type;}
    void setTripCost(float cost){tripCost = cost;}

    vector<Transport> getTransportType(){return transportType;}
    vector<Hotel> getPlace(){return place;}
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
        for(auto& t : transportType){
            t.printTransport();
        }
        for(auto& h : place){
            h.printHotel();
        }        
        cout << "Number of people: " << numberOfPeople;
        cout <<"\n\t-> Trip cost: " << tripCost;
    }
};

#endif