#ifndef __ACCOUNT__
#define __ACCOUNT__

#include "trip.hpp"

class Account{
protected:
    string accountName;
    string accountPassword;
public:
    void logIn();
    //void logOut();
    void searchRoomByLocation();
    void searchTransportByLocation();
    void arrangeTripByTime();
    void arrangeTripByCost();
    void listAvailableService();
};

class User : public Account{
public:
    //void signUp();
    void addTransport();
    void addHotel();
    void editPersonalInformation();
    void viewTripInformation();
    void editTripInformation();
    void cancelTripHandles();
};

class Admin : public Account{
public:
    void viewListUserAccount();
    void editUserAccount();
    void deleteUserAccount();
    void viewServiceInformation();
    void addServiceInformation();
    void deleteServiceInformation();
    void saveSystemData();
    void loadSystemData();
};
#endif