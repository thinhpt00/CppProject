#include "transport.hpp"

void Transport::addTransport(){
    cout << "\n1:Airline\t2:Car\n";
    cout << "\nEnter number in range 1 - 2: ";
    int n; cin >> n;
    while(n > 2 || n < 1){
         cout << "\nRe-Enter number in range 1 - 2: ";
         cin >> n;
    }
    if(n == 1){
        transportName = "Airline";
    }
    else if(n == 2){
        transportName = "Car";
    }
    cout << "\nEnter brand: ";
    cin.ignore();
    getline(cin,transportBrand);
    cout << "\nEnter from: ";
    cin.ignore();
    getline(cin,departurePlace);
    cout << "\nEnter To: ";
    cin.ignore();
    getline(cin,destination);
    cout << "\nEnter from Date (dd-mm-yy): ";
    cin >> departureDay;
}