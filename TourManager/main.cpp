#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\trip.hpp"
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\account.hpp"
using namespace std;
const string adminAccountName = "admin";
const string adminAccountPassword = "111";
//
void mainMenu();
void UserMenu();
void AdminMenu();
// Sắp xếp
bool increase(Trip a, Trip b){return a < b;}
bool decrease(Trip a, Trip b){return a > b;}
void arrangeTrip(vector<Trip>& trip);
// save, read from txt file
vector<User> readUserInformationFromTextFile(const string& fileName);
vector<Transport> readTransportInformationFromTextFile(const string& fileName);
vector<Hotel> readHotelInformationFromTextFile(const string& fileName);
void saveUserInformationToTextFile(const string &filename, const vector<User> &user);
void SaveTransportToTextFile(const string &filename, const vector<Transport> &transport);
void SaveHotelToTextFile(const string &filename, const vector<Hotel> &hotel);
// Login
    // User
void AddTrip(Trip& trip);
float AddHotel(vector<Hotel>& hotelList, map<int, Hotel>& hotelMap, Trip& trip, vector<Hotel>& hotelVectorInTrip);
float AddTransport(vector<Transport>& transportList, map<int,Transport>& transportMap, Trip& trip, vector<Transport>& transportVectorInTrip);
void EditPersonalInformation(vector<User>& userList,string& loginName, string& loginPassword);
void CancelTripHandles(vector<Trip>& tour);
    // Admin
        // 1
void ViewListUserAccount(vector<User>& userList);
void DeleteUserAccount(map<string,vector<Trip>> booKing);
void EditUserAccount(vector<User>& userList);
        // 2
void AddNewHotel(vector<Hotel>& hotelList, map<int, Hotel>& hotelMap);
void AddNewTransport(vector<Transport>& transportList, map<int,Transport>& transportMap);

// Sign Up
void SignUp(vector<User>& userList);
// Search Room
void SearchRoomByLocation(vector<Hotel>& hotelList);
// Search Transport
void SearchTransportByLocation(vector<Transport>& transportList);

int main(){
    //user
    vector<User> userList;
    userList = readUserInformationFromTextFile("userData.txt");
    // Trip
    vector<Trip> tripList;
    map<int,Trip> tripMap;
    map<string,vector<Trip>> booKing;
    // Transport
    vector<Transport> transportList;
    map<int,Transport> transportMap;
    transportList = readTransportInformationFromTextFile("transport.txt");
    // Hotel
    vector<Hotel> hotelList;
    map<int,Hotel> hotelMap;
    hotelList = readHotelInformationFromTextFile("hotel.txt");

    int n = -1;
    do{
        //system("cls");
        mainMenu();
        cout << "\n\nEnter number in range 0 - 6: "; 
        cin >> n;
        if(cin.fail()){
            n = -1;
            cin.clear();
            cin.ignore();
        }
        if(n == 1){
            //vector
            string loginName, loginPassword;
            cout << "\nEnter username: ";
            cin >> loginName;
            cout << "\nEnter password: ";
            cin >> loginPassword;
            if(loginName == adminAccountName && loginPassword == adminAccountPassword){
                int n4;
                do{
                    AdminMenu();
                    cin >> n4;
                    if(n4 == 1){
                        int n5;
                        do{
                            cout << "\n\t1: View List User Account";
                            cout << "\n\t2: Edit User Account";
                            cout << "\n\t3: Delete User Account";
                            cout << "\n\t0: Done";
                            cout << "\nEnter number in range 0 - 3: ";
                            cin >> n5;
                            if(n5 == 1){
                                ViewListUserAccount(userList);
                            }
                            else if(n5 == 2){
                                EditUserAccount(userList);
                            }
                            else if(n5 == 3){
                                DeleteUserAccount(booKing);
                            }       
                        }while(n5 != 0);                       
                    }                   
                    else if(n4 == 2){
                        int n5;
                        do{
                            cout << "\n\t1: Hotel Information";
                            cout << "\n\t2: Transport Information";
                            cout << "\n\t0: Done";
                            cout << "\nEnter number in range 0 - 2: ";
                            cin >> n5;
                            if(n5 == 1){
                                int n6;
                                do{
                                    cout << "\n\t1: View Hotel Information";
                                    cout << "\n\t2: Add Hotel";
                                    cout << "\n\t3: Delete Hotel";
                                    cout << "\n\t0: Done";
                                    cout << "\nEnter number in range 0 - 3: ";
                                    cin >> n6;
                                    if(n6 == 1){
                                        for(int i = 0; i < hotelList.size(); ++i){
                                            cout << endl << i+1 << " - ";  hotelList[i].printHotel();
                                        }
                                    }
                                    else if(n6 == 2){
                                        int n7;
                                        do{
                                            cout << "\n\t1: Add Hotel";
                                            cout << "\n\t0: Done";
                                            cout << "\nEnter number in range (0 - 1): ";
                                            cin >> n7;
                                            if(n7 == 1){
                                                AddNewHotel(hotelList,hotelMap);
                                            }
                                        }while(n7 != 0);                                       
                                    }
                                    else if(n6 == 3){
                                        int n7;
                                        do{
                                            cout << "\n\t1: Delete Hotel";
                                            cout << "\n\t0: Done";
                                            cout << "\nEnter number in range (0 - 1): ";
                                            cin >> n7;
                                            if(n7 == 1){
                                                cout << "\nWhat hotel do you want to delete? ";
                                                cout << "\nEnter number in range (1 - " << hotelList.size() << "): ";
                                                int index; cin >> index;
                                                hotelList.erase(hotelList.begin() + index - 1);
                                            }
                                        }while(n7 != 0);                                          
                                    }       
                                }while(n6 != 0);
                            }
                            else if(n5 == 2){
                                int n6;
                                do{
                                    cout << "\n\t1: View Transport Information";
                                    cout << "\n\t2: Add Transport ";
                                    cout << "\n\t3: Delete Transport ";
                                    cout << "\n\t0: Done";
                                    cout << "\nEnter number in range 0 - 3: ";
                                    cin >> n6;
                                    if(n6 == 1){
                                        for(int i = 0; i < transportList.size(); ++i){
                                            cout << endl << i+1 << " - ";  transportList[i].printTransport();
                                        }
                                    }
                                    else if(n6 == 2){
                                        int n7;
                                        do{
                                            cout << "\n\t1: Add Transport";
                                            cout << "\n\t0: Done";
                                            cout << "\nEnter number in range (0 - 1): ";
                                            cin >> n7;
                                            if(n7 == 1){
                                                AddNewTransport(transportList,transportMap);
                                            }
                                        }while(n7 != 0); 
                                    }
                                    else if(n6 == 3){
                                        int n7;
                                        do{
                                            cout << "\n\t1: Delete Transport";
                                            cout << "\n\t0: Done";
                                            cout << "\nEnter number in range (0 - 1): ";
                                            cin >> n7;
                                            if(n7 == 1){
                                                cout << "\nWhat transport do you want to delete? ";
                                                cout << "\nEnter number in range (1 - " << transportList.size() << "): ";
                                                int index; cin >> index;
                                                transportList.erase(transportList.begin() + index - 1);
                                            }
                                        }while(n7 != 0);                                        
                                    }       
                                }while(n6 != 0);
                            }      
                        }while(n5 != 0); 
                    }
                    else if(n4 == 3){
                        int n5;
                        do{
                            cout << "\n\t1: Save System Data";
                            cout << "\n\t2: Load System Data";  
                            cout << "\n\t0: Done";
                            cout << "\nEnter number in range 0 - 2: ";
                            cin >> n5;
                            if(n5 == 1){
                                //
                            }
                            else if(n5 == 2){
                                //
                            }       
                        }while(n5 != 0); 
                    }
                }while(n4 != 0);                
            }
            else{
                bool check = false;
                for(auto& u : userList){
                    if(loginName == u.getAccountName() && loginPassword == u.getAccountPassword() ){
                        check = true;
                    }
                }
                if(check == false){
                    cout << "\nLogin failed!";
                }
                else{
                    vector<Trip> tour;
                    vector<Hotel> HOTEL;
                    vector<Transport> TRANSPORT;
                    int n2; 
                    do{
                        UserMenu();
                        cin >> n2;
                        if(n2 == 0){break;}
                        else if(n2 == 1){
                            //Trip
                            Trip trip;
                            float trip_cost;
                            float hotel_cost = 0;
                            float transport_cost = 0;
                            AddTrip(trip);
                            int n5;
                            do{
                                cout << "\n\t1: Add Hotel";
                                cout << "\n\t2: Add Transport";
                                cout << "\n\t0: Done";
                                cin >> n5;
                                if(n5 == 1){
                                    hotel_cost += AddHotel(hotelList,hotelMap,trip,HOTEL);
                                }
                                else if( n5 == 2){
                                    transport_cost += AddTransport(transportList,transportMap,trip,TRANSPORT);
                                }
                            }while(n5 != 0);
                            trip_cost = (hotel_cost + transport_cost) * trip.getNumberOfPeople();
                            trip.setTripCost(trip_cost);                            
                            tour.push_back(trip);
                            tripList.push_back(trip);
                            //
                        }
                        else if(n2 == 2){
                            EditPersonalInformation(userList,loginName,loginPassword);
                        }
                        else if(n2 == 3){
                            for(auto& trip : tour){
                                trip.printTrip();
                            }
                        }
                        else if(n2 == 4){

                        }
                        else if(n2 == 5){
                            CancelTripHandles(tour);
                        }
                    }
                    while(n2!=0);
                    booKing[loginName] = tour;
                }
            }
        }
        else if(n == 2){
            SignUp(userList);
        }
        else if(n == 3){
            SearchRoomByLocation(hotelList);
        }
        else if(n == 4){
            SearchTransportByLocation(transportList);
        }
        else if(n == 5){
            arrangeTrip(tripList);
        }
        else if(n == 6){
            
        }

    }while (n!=0);

// Back-up data username, password to text file
    saveUserInformationToTextFile("userData.txt",userList);
    SaveTransportToTextFile("transport.txt", transportList);
    SaveHotelToTextFile("hotel.txt", hotelList);
/////////////
    return 0;
}

void mainMenu(){
    cout << "\n\nMenu:";
    cout << "\n\t6: Arrange Trip By Time";
    cout << "\n\t5: Arrange Trip By Cost";
    cout << "\n\t4: Search Transport By Location";
    cout << "\n\t3: Search Room By Location";   
    cout << "\n\t2: Sign up";
    cout << "\n\t1: Log in";
    cout << "\n\t0: Exit";
}
void UserMenu(){
    cout << "\nHello, User!\nWhat do you want?";
    cout << "\n\t1: Add Tour Information";
    cout << "\n\t2: Edit Personal Information";
    cout << "\n\t3: View Trip Information";
    cout << "\n\t4: Edit Trip Information";
    cout << "\n\t5: Cancel Trip Handles";
    cout << "\n\t0: Done";
    cout << "\nEnter number in range 0 - 5: ";
}
void AdminMenu(){
    cout << "\nHello, Admin!\nWhat do you want?";
    cout << "\n\t1: User Account";   
    cout << "\n\t2: Service Information";
    cout << "\n\t3: System Data";
    cout << "\n\t0: Done";
    cout << "\nEnter number in range 0 - 3: ";
}

void arrangeTrip(vector<Trip>& trip){
    int n; 
    do{
        cout << "\nArrange Trip By Cost: ";
        cout << "\n2: Decreasing";
        cout << "\n1: Increasing";
        cout << "\n0: Done";
        cout << "\nEnter number in range 0 - 2: ";
        cin >> n;
        if(n == 1){sort(trip.begin(), trip.end(), increase);}
        else if(n == 2){sort(trip.begin(), trip.end(), decrease);}
    }while(n != 0);
}
vector<User> readUserInformationFromTextFile(const string& fileName){
    vector<User> x;
    ifstream file(fileName);
    if (file.is_open()) {
        string data;
        while(getline(file, data)){
            stringstream ss(data);
            vector<string> s;
            string word;
            while (getline(ss, word, ';')) {
                s.push_back(word);
            }
            User user;
            user.setAccountName(s[0]);
            user.setAccountPassword(s[1]);
            user.setName(s[2]);
            user.setAge(stoi(s[3]));
            user.setAddress(s[4]);
            x.push_back(user);
        }
        file.close();
    }
    return x;
}
void saveUserInformationToTextFile(const string &filename, const vector<User> &user){
    ofstream file(filename);
    if (file.is_open()){
    for (auto U : user){
        file << U.getAccountName() << ";" << U.getAccountPassword() << ";" << U.getName() << ";" << U.getAge() << ";" << U.getAddress() << ";" << endl;
    }
    file.close();
    }
}
void SaveHotelToTextFile(const string &filename, const vector<Hotel> &hotel){
    ofstream file(filename);
    if (file.is_open()){
    for (auto h : hotel){
        file << h.getHotelName() << ";" << h.getHotelAddress() << ";" << h.getRoomType() << ";" << h.getStartDay() << ";" << h.getRoomPrice() << ";" << endl;
    }
    file.close();
    }
}
void SaveTransportToTextFile(const string &filename, const vector<Transport> &transport){
    ofstream file(filename);
    if (file.is_open()){
    for (auto h : transport){
        file << h.getTransportBrand() << ";" << h.getTransportName() << ";" << h.getDeparturePlace() << ";" << h.getDestination() << ";" << h.getDepartureDay() << ";" << h.getTicketPrice() << ";" << endl;
    }
    file.close();
    }
}
vector<Transport> readTransportInformationFromTextFile(const string& fileName){
    vector<Transport> x;
    ifstream file(fileName);
    if (file.is_open()) {
        string data;
        while(getline(file, data)){
            stringstream ss(data);
            vector<string> s;
            string word;
            while (getline(ss, word, ';')) {
                s.push_back(word);
            }
            Transport transport_;
            transport_.setTransportBrand(s[0]);
            transport_.setTransportName(s[1]);
            transport_.setDeparturePlace(s[2]);
            transport_.setDestination(s[3]);
            transport_.setDepartureDay(s[4]);
            transport_.setTicketPrice(stof(s[5]));
            x.push_back(transport_);
        }
        file.close();
    }
    return x;
}
vector<Hotel> readHotelInformationFromTextFile(const string& fileName){
    vector<Hotel> x;
    ifstream file(fileName);
    if (file.is_open()) {
        string data;
        while(getline(file, data)){
            stringstream ss(data);
            vector<string> s;
            string word;
            while (getline(ss, word, ';')) {
                s.push_back(word);
            }
            Hotel hotel_;
            hotel_.setHotelName(s[0]);
            hotel_.setHotelAddress(s[1]);
            hotel_.setRoomType(s[2]);
            hotel_.setStartDay(s[3]);
            hotel_.setRoomPrice(stof(s[4]));
            x.push_back(hotel_);
        }
        file.close();
    }
    return x;
}
void AddTrip(Trip& trip){
    string str1,str2,str3,str4;
    int numPeople;
    cout <<"\n\tEnter Trip Information!";
    cout << "\nEnter from: ";
    cin.ignore();
    getline(cin,str1);
    cout << "\nEnter to: ";
    getline(cin,str2);
    cout << "\nEnter from Date: ";
    getline(cin,str3);
    cout << "\nEnter to Date: ";
    getline(cin,str4);
    cout << "\nEnter number of peple: ";
    cin >> numPeople;
    trip.setStartLocation(str1);
    trip.setEndLocation(str2);
    trip.setFromDate(str3);
    trip.setToDate(str4);
    trip.setNumberOfPeople(numPeople);
}
float AddHotel(vector<Hotel>& hotelList, map<int, Hotel>& hotelMap, Trip& trip, vector<Hotel>& hotelVectorInTrip){
    string address,date;
    cout << "\nEnter hotel address: ";
    cin.ignore();
    getline(cin,address);
    cout << "\nEnter from date (dd-mm-yy): ";
    cin >> date;
    int i = 0;
    for(auto& h : hotelList){
        if(h.getHotelAddress() == address){
            i++; 
            cout << "\n\t" << i << " - "; h.printHotel();
            hotelMap[i] = h;                                      
        }
    }
    cout << "\nEnter number in range 1 - " << i << " : ";
    int check; cin >> check;
    float hotel_cost;
    for(auto& m : hotelMap){
        if(m.first == check){
            hotelVectorInTrip.push_back(m.second);
            trip.setPlace(hotelVectorInTrip);
            hotel_cost = m.second.getRoomPrice();
            break;
        }
    }
    return hotel_cost;
}
float AddTransport(vector<Transport>& transportList, map<int,Transport>& transportMap, Trip& trip, vector<Transport>& transportVectorInTrip){
    string from,to,day;
    cout << "\nEnter from: ";
    cin.ignore();
    getline(cin,from);
    cout << "\nEnter from date (dd-mm-yy): ";
    cin >> day;
    cout << "\nEnter to: ";
    cin.ignore();
    getline(cin,to);
    int j = 0;
    for(auto& t : transportList){
        if(t.getDeparturePlace() == from && t.getDestination() == to){
            j++;
            cout << "\n\t" << j << " - "; t.printTransport();                                   
            transportMap[j] = t;                                    
        }
    }
    cout << "\nEnter number in range 1 - " << j << " : ";
    int check1; cin >> check1;
    float transport_cost;
    for(auto& m : transportMap){
        if(m.first == check1){
            transportVectorInTrip.push_back(m.second);
            trip.setTransportType(transportVectorInTrip);
            transport_cost = m.second.getTicketPrice();
            break;
        }
    }
    return transport_cost;
}
void EditPersonalInformation(vector<User>& userList,string& loginName, string& loginPassword){
    int n3;
    do{
        cout << "\nEnter information you want to edit: ";
        cout << "\n\t1: Full name";
        cout << "\n\t2: Age";
        cout << "\n\t3: Address";
        cout << "\n\t4: Password";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range (0 - 4): ";
        cin >> n3;
        int index = 0;
        for(int i = 0; i < userList.size(); i++){
            if(loginName == userList[i].getAccountName() && loginPassword == userList[i].getAccountPassword() ){
                index = i;
                break;
            }
        }
        if(n3 == 1){
            cout << "\nEnter new full name: ";
            string fullName;
            cin.ignore();
            getline(cin,fullName);
            userList[index].setName(fullName);
            cout << "\n\t->New name edited!";
        }
        else if(n3 == 2){
            cout << "\nEnter new age: ";
            int age_;
            cin >> age_;
            userList[index].setAge(age_);
            cout << "\n\t->New age edited!";
        }
        else if(n3 == 3){
            cout << "\nEnter new address: ";
            string address_;
            cin.ignore();
            getline(cin,address_);
            userList[index].setAddress(address_);
            cout << "\n\t->New address edited!";
        }
        else if(n3 == 4){
            cout << "\nEnter new password: ";
            string pass_;
            cin.ignore();
            getline(cin,pass_);
            userList[index].setAccountPassword(pass_);
            cout << "\n\t->New Password edited!";
        }                                
    }while(n3 != 0);
}
void CancelTripHandles(vector<Trip>& tour){
    int cancel;
    do{
        cout << "\n1: Cancel trip";
        cout << "\n0: Done";
        cout << "\nEnter number in range (0 - 1): ";
        cin >> cancel;
        if(cancel == 1){
            cout << "\n\tEnter trip you want to cancel (1 - " << tour.size() << "): ";
            int cancel_trip;
            cin >> cancel_trip;
            tour.erase(tour.begin() + cancel_trip - 1);
        }
    }while(cancel != 0);
}
void SignUp(vector<User>& userList){
    string user_name,pass,name,addr;
    cout << "\nEnter your username: ";
    cin.ignore();
    getline(cin,user_name);
    cout << "\nEnter your password: ";
    getline(cin,pass);
    cout << "\nEnter your full name: ";
    getline(cin,name);
    cout << "\nEnter your age: ";
    int AGE; cin >> AGE;
    cout << "\nEnter your address: ";
    cin.ignore();
    getline(cin,addr);
    User user;
    user.setAccountName(user_name);
    user.setAccountPassword(pass);
    user.setName(name);
    user.setAge(AGE);
    user.setAddress(addr);
    userList.push_back(user);          
    cout << "\n\tUser Account Sign up Successfully\n\n";
}
void SearchRoomByLocation(vector<Hotel>& hotelList){
    cout << "\nWhere do you want to find hotel? ";
    string find_hotel;
    cin.ignore();
    getline(cin,find_hotel);
    for(auto& h : hotelList){
        if(h.getHotelAddress() == find_hotel){
            h.printHotel();
        }
    }
}
void SearchTransportByLocation(vector<Transport>& transportList){
    cout << "\nWhere do you want to find transport? ";
    string find_transport;
    cin.ignore();
    getline(cin,find_transport);
    for(auto& t : transportList){
        if(t.getDeparturePlace() == find_transport){
            t.printTransport();
        }
    }
}
void ViewListUserAccount(vector<User>& userList){
    cout << "\n------------List User Account------------";
    for(int i = 0; i < userList.size(); ++i){
        cout << "Account " << i+1 << ": " << userList[i].getAccountName() << endl;
    }
}
void DeleteUserAccount(map<string,vector<Trip>> booKing){
    cout << "\n------------Delete User Account------------";
    cout << "\nWhich account do you want to delete? ";
    cout << "\nEnter username: ";
    string user_name;
    cin >> user_name;
    bool check1 = false;
    for(auto& m : booKing){
        if(m.first == user_name){
            check1 = true;
            booKing.erase(user_name);
            break;
        } 
    }
    if(check1 == false){
        cout << "\nDo not exist account " << user_name << "!!";
    }
}
void EditUserAccount(vector<User>& userList){
    int n;
    do{       
        cout << "\n------------Edit User Account------------";
        cout << "\n\t1: Enter account";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range (0-1): ";
        cin >> n;
        if(n == 1){
            cout << "\nEnter account you want to edit: ";
            string acc;
            cin >> acc;
            for(auto& u : userList){
                if(acc == u.getAccountName()){
                    string new_acc;
                    cin >> new_acc;
                    u.setAccountName(new_acc);
                    cout << "\n\t->New account edited!";
                    break;
                }
            }  
        }       
    }while(n != 0);
}
void AddNewHotel(vector<Hotel>& hotelList, map<int, Hotel>& hotelMap){
    Hotel x;
    string hotel_name,address,room_type,date;
    int price;
    cout << "\nEnter new hotel name: ";
    cin.ignore();
    getline(cin,hotel_name);
    cout << "\nEnter new hotel address: ";
    getline(cin,address);
    cout << "\nEnter new hotel room type: ";
    getline(cin,room_type);
    cout << "\nEnter new start day: ";
    getline(cin,date);
    cout << "\nEnter new room price: ";
    cin >> price;
    x.setHotelName(hotel_name);
    x.setHotelAddress(address);
    x.setRoomType(room_type);
    x.setStartDay(date);
    x.setRoomPrice(price);
    hotelList.push_back(x);
    hotelMap[hotelList.size()] = x;
}
void AddNewTransport(vector<Transport>& transportList, map<int,Transport>& transportMap){
    string transportName,transportBrand,departureDay,departurePlace,destination;
    float ticketPrice;
    Transport x;
    cout << "\n\tEnter new Transport";
    cout << "\nEnter brand: ";
    cin.ignore();
    getline(cin,transportBrand);
    cout << "\nEnter name: ";
    getline(cin,transportName);
    cout << "\nEnter start day: ";
    getline(cin,departureDay);
    cout << "\nEnter start place: ";
    getline(cin,departurePlace);
    cout << "\nEnter destination: ";
    getline(cin,destination);
    cout << "\nEnter ticket price: ";
    cin >> ticketPrice;
    x.setTransportBrand(transportBrand);
    x.setTransportName(transportName);
    x.setDepartureDay(departureDay);
    x.setDeparturePlace(departurePlace);
    x.setDestination(destination);
    x.setTicketPrice(ticketPrice);
    transportList.push_back(x);
    transportMap[transportList.size()] = x;
}
