#ifndef __CLASS__
#define __CLASS__

#include "Header.hpp"

class Hotel{
private:
    string hotelName;
    string hotelAddress;
    string roomType;
    string startDay;
    float roomPrice;
public:
    void setHotelName(string name){hotelName = name;}
    void setHotelAddress(string address){hotelAddress = address;}
    void setRoomType(string type){roomType = type;}
    void setStartDay(string day){startDay = day;};
    void setRoomPrice(float price){roomPrice = price;}

    string getHotelName(){return hotelName;}
    string getHotelAddress(){return hotelAddress;}
    string getRoomType(){return roomType;}
    string getStartDay(){return startDay;}
    float getRoomPrice(){return roomPrice;}

    void printHotel(){
        cout << "Hotel: "  << hotelName << " " << hotelAddress << " " << roomType << " " << startDay << " " << roomPrice << endl;
    }

};

class Transport{
private:
    string transportName;
    string transportBrand;
    string departureDay;
    string departurePlace;
    string destination;
    float ticketPrice;
public:
    Transport(){};
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

class User{
private:
    string accountName;
    string accountPassword;
    string name;
    int age;
    string address;
public:
    void setAccountName(string name){accountName = name;}
    void setAccountPassword(string pass){accountPassword = pass;}
    void setName(string name_){name = name_;}
    void setAge(int age_){age = age_;}
    void setAddress(string addr){address = addr;}

    string getAccountName(){return accountName;}
    string getAccountPassword(){return accountPassword;}
    string getName(){return name;}
    int getAge(){return age;}
    string getAddress(){return address;}

    void printUser(){
        cout << accountName << " " << accountPassword << " " << name << " " << age << " " << address << endl;
    }
};

class Account{
private:
    User client;
    vector<Trip> TOUR;
public:
    void setUserAccount(User x){client = x;}
    void setTourOfCLient(vector<Trip> x){TOUR = x;}

    User getUserAccount(){return client;}
    vector<Trip> getTourOfCLient(){return TOUR;}
};

#endif