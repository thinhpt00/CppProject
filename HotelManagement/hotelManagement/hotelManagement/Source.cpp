﻿#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int qRoom = 0, qChicken = 0, qHotDog = 0, qFish = 0, qPizza = 0;
    int sRoom = 0, sChicken = 0, sHotDog = 0, sFish = 0, sPizza = 0;
    int Total = 0;

    //cout << "\n\tEnter items\n";
    //cout << "\nEnter Room: "; cin >> qRoom;
    //cout << "\nEnter Chicken: "; cin >> qChicken;
    //cout << "\nEnter Hotdog: "; cin >> qHotDog;
    //cout << "\nEnter Fish: "; cin >> qFish;
    //cout << "\nEnter Pizza: "; cin >> qPizza;

label:
    char x = 33; // dấu +
    
    cout << "\n\t+";
    for (int i = 0; i < 48; ++i) {
        cout << "-";
    }
    
    cout  << "+\n\t" << setw(49) << left << "|                      Menu" << "|";
    
    cout << "\n\t|";
    for (int i = 0; i < 48; ++i) {
        cout << "-" ;
    }
    cout << "|";
    
    cout << "\n\t|" << setw(48) << left << "                   (1) Room" << "|";

    cout << "\n\t|";
    for (int i = 0; i < 48; ++i) {
        cout << "-";
    }
    cout << "|";

    cout << "\n\t|" << setw(12) << left << "(2) Chicken" << setw(12) << left << "|(3) Hotdog"
                    << setw(12) << left << "| (4) Fish" << setw(12) << left << "| (5) Pizza" << "|";

    cout << "\n\t" <<  setfill('-') << setw(13) << left << "|" << setw(12) << left << x
                    << setw(12) << left << "|" << setw(12) << left << x << "|";

    cout << "\n\t|" << setfill(' ') << setw(24) << left << "       (6) Detail" << setw(24) << left << "|       (7) Exit" << "|";

    cout << "\n\t" << setfill('-') << setw(25) << left << "+" << setw(24) << left << x << "+";

    cout << setfill(' ');

    int choice;
    cout << "\n\n\tPlease select your choice!\n"; cin >> choice;
    switch (choice) {
    case 1:
        int room;
        cout << "\nEnter room quantity: "; cin >> room;
        if (qRoom - sRoom >= room) {
            sRoom += room;
            cout << "\n" << room << " rooms have been booked!";
        }
        else {
            cout << "Only " << qRoom - sRoom << " rooms is remaining. Please re-enter the number of rooms you want to book!\n";
        }
        break;
    case 2:
        int chicken;
        cout << "\nEnter Chicken quantity: "; cin >> chicken;
        if (qChicken - sChicken >= chicken) {
            sChicken += chicken;
            cout << "\n" << chicken << " chickens have been ordered!";
        }
        else {
            cout << "Only " << qChicken - sChicken << " chickens is remaining. Please re-enter the number of chickens you want to order!\n";
        }
        break;
    case 3:
        int HotDog;
        cout << "\nEnter hotdog quantity: "; cin >> HotDog;
        if (qHotDog - sHotDog >= HotDog) {
            sHotDog += HotDog;
            cout << "\n" << HotDog << " hotdogs have been ordered!";
        }
        else {
            cout << "Only " << qHotDog - sHotDog << " hotdogs is remaining. Please re-enter the number of hotdogs you want to order!\n";
        }
        break;
    case 4:
        int Fish;
        cout << "\nEnter Fish quantity: "; cin >> Fish;
        if (qFish - sFish >= Fish) {
            sFish += Fish;
            cout << "\n" << Fish << " fishs have been ordered!";
        }
        else {
            cout << "Only " << qFish - sFish << " fishs is remaining. Please re-enter the number of fishs you want to order!\n";
        }
        break;
    case 5:
        int Pizza;
        cout << "\nEnter Pizza quantity: "; cin >> Pizza;
        if (qPizza - sPizza >= Pizza) {
            sPizza += Pizza;
            cout << "\n" << Pizza << " pizzas have been ordered!";
        }
        else {
            cout << "Only " << qPizza - sPizza << " pizzas is remaining. Please re-enter the number of pizzas you want to order!\n";
        }
        break;
    case 6:
        cout << "\t\tTotal:\n";
        cout << "\n\tRoom: " << qRoom;
        cout << "\n\tChicken: " << qChicken;
        cout << "\n\tHotdog: " << qHotDog;
        cout << "\n\tFish: " << qFish;
        cout << "\n\tPizza: " << qPizza;
        cout << "\n\n\t\tRemaining:\n";
        cout << "\n\tRoom: " << qRoom - sRoom;
        cout << "\n\tChicken: " << qChicken - sChicken;
        cout << "\n\tHotdog: " << qHotDog - sHotDog;
        cout << "\n\tFish: " << qFish - sFish;
        cout << "\n\tPizza: " << qPizza - sPizza;
        break;
    case 7:
        exit(0);
    default:
        cout << "\nPlease select again!";
        break;
    }
    goto label;

}