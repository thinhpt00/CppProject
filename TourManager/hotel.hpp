#ifndef __HOTEL__
#define __HOTEL__


//#include <vector>
// #include <string>
#include "Header.hpp"
// using namespace std;

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
    string getStartDay(){return startDay;};
    float getRoomPrice(){return roomPrice;}

    void addHotel(){
        cout << "\nEnter hotel address: ";
        cin.ignore();
        getline(cin,hotelAddress);
        cout << "\nEnter from date (dd-mm-yy): ";
        cin >> startDay;
    }
    void printHotel(){
        cout << "Hotel: "  << hotelName << " " << hotelAddress << " " << roomType << " " << startDay << " " << roomPrice << endl;
    }

};



#endif