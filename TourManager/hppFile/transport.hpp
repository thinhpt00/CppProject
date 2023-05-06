#ifndef __TRANSPORT__
#define __TRANSPORT__

//#include "date.hpp"
#include<string>
#include<iostream>
using namespace std;

class Transport{
private:
    string transportName;
    string transportBrand;
    string departureDay;
    string departurePlace;
    string destination;
    float ticketPrice;
public:
    void setTransportName(string name){transportName = name;}
    void setTransportBrand(string brand){transportBrand = brand;}
    void setDepartureDay(string day){departureDay = day;}
    void setDeparturePlace(string place){departurePlace = place;}
    void setDestination(string des){destination = des;}
    void setTicketPrice(float price){ticketPrice = price;}

    string getTransportName(){return transportName;}
    string getTransportBrand(){return transportBrand;}
    string getDepartureDay(){return departureDay;}
    string getDeparturePlace(){return departurePlace;}
    string getDestination(){return destination;}
    float getTicketPrice(){return ticketPrice;}

    void printTransport(){
        cout << transportBrand << " " <<  transportName << " " <<  departurePlace << " " <<  destination << " " <<  departureDay << " " <<  ticketPrice << " " << endl;
    }
};


#endif
