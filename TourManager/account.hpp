#ifndef __ACCOUNT__
#define __ACCOUNT__

#include "trip.hpp"

// class Account{
// protected:
//     string accountName;
//     string accountPassword;
// public:
//     void logIn();
//     //void logOut();
//     void searchRoomByLocation();
//     void searchTransportByLocation();
//     void arrangeTripByTime();
//     void arrangeTripByCost();
//     void listAvailableService();
// };

// class User : public Account{
// public:
//     //void signUp();
//     void addTransport();
//     void addHotel();
//     void editPersonalInformation();
//     void viewTripInformation();
//     void editTripInformation();
//     void cancelTripHandles();
// };

// class Admin : public Account{
// public:
//     void viewListUserAccount();
//     void editUserAccount();
//     void deleteUserAccount();
//     void viewServiceInformation();
//     void addServiceInformation();
//     void deleteServiceInformation();
//     void saveSystemData();
//     void loadSystemData();
// };

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

#endif