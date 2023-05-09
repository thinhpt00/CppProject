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
// Sắp xếp
bool increase(Trip a, Trip b){return a < b;}
bool decrease(Trip a, Trip b){return a > b;}
void arrangeTrip(vector<Trip>& trip);
// save, read from txt file
vector<User> readUserInformationFromTextFile(const string& fileName);
void saveUserInformationToTextFile(const string &filename, const vector<User> &user);
vector<Transport> readTransportInformationFromTextFile(const string& fileName);
vector<Hotel> readHotelInformationFromTextFile(const string& fileName);
void AddTrip(Trip& trip);
float AddHotel(vector<Hotel>& hotelList, map<int, Hotel>& hotelMap, Trip& trip, vector<Hotel>& hotelVectorInTrip);
float AddTransport(vector<Transport>& transportList, map<int,Transport>& transportMap, Trip& trip, vector<Transport>& transportVectorInTrip);

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
                    cout << "\nHello, Admin!\nWhat do you want?";
                    cout << "\n\t1: View List User Account";
                    cout << "\n\t2: Edit User Account";
                    cout << "\n\t3: Delete User Account";
                    cout << "\n\t4: viewServiceInformation";
                    cout << "\n\t5: addServiceInformation";
                    cout << "\n\t6: deleteServiceInformation";
                    cout << "\n\t7: saveSystemData";
                    cout << "\n\t8: loadSystemData";
                    cout << "\n\t0: Done";
                    cout << "\nEnter number in range 0 - 8: ";
                    cin >> n4;
                    if(n4 == 1){
                        cout << "\n------------List User Account------------";
                        for(int i = 0; i < userList.size(); ++i){
                            cout << "Account " << i+1 << ": " << userList[i].getAccountName() << endl;
                        }
                    }
                    else if(n4 == 2){

                    }
                    else if(n4 == 3){
                        cout << "\n------------Delete User Account------------";
                        cout << "\nWhich account do you want to delete? ";
                        cout << "\nEnter username: ";
                        string user_name;
                        cin >> user_name;
                        bool check1 = false;
                        int index = 0;
                        for(int i = 0; i < userList.size(); ++i){
                            if(userList[i].getAccountName() == user_name){
                                check1 = true;
                                index = i;
                                break;
                            } 
                        }
                        if(check1 == false){
                            cout << "\nDo not exist account " << user_name << "!!";
                        }
                        else{
                            userList.erase(userList.begin() + index - 1);
                        }
                    }
                    else if(n4 == 4){
                        
                    }
                    else if(n4 == 5){
                        
                    }
                    else if(n4 == 6){
                        
                    }
                    else if(n4 == 7){
                        
                    }
                    else if(n4 == 8){
                        
                    }
                }while(n4 != 0);
                
            }
            else{
                bool check = false;
                // for(auto& x : saveDataToText){
                //     if(loginName == x.first && loginPassword == x.second){
                //         check = true;
                //     }
                // }
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
                        cout << "\nHello, User!\nWhat do you want?";
                        cout << "\n\t1: Add Tour Information";
                        cout << "\n\t2: Edit Personal Information";
                        cout << "\n\t3: View Trip Information";
                        cout << "\n\t4: Edit Trip Information";
                        cout << "\n\t5: Cancel Trip Handles";
                        cout << "\n\t0: Done";
                        cout << "\nEnter number in range 0 - 5: ";
                        cin >> n2;
                        if(n2 == 0){break;}
                        else if(n2 == 1){
                            //Trip
                            Trip trip;
                            // string str1,str2,str3,str4;
                            // int numPeople;
                            // cout <<"\n\tEnter Trip Information!";
                            // cout << "\nEnter from: ";
                            // cin.ignore();
                            // getline(cin,str1);
                            // //cout << "\n\t" << str1;
                            // cout << "\nEnter to: ";
                            // //cin.ignore();
                            // getline(cin,str2);
                            // //cout << "\n\t" << str2;
                            // cout << "\nEnter from Date: ";
                            // //cin.ignore();
                            // getline(cin,str3);
                            // //cout << "\n\t" << str3;
                            // cout << "\nEnter to Date: ";
                            // //cin.ignore();
                            // getline(cin,str4);
                            // //cout << "\n\t" << str4;
                            // cout << "\nEnter number of peple: ";
                            // cin >> numPeople;
                            // trip.setStartLocation(str1);
                            // trip.setEndLocation(str2);
                            // trip.setFromDate(str3);
                            // trip.setToDate(str4);
                            // trip.setNumberOfPeople(numPeople);

                            //Hotel
                            // string address,date;
                            // cout << "\nEnter hotel address: ";
                            // cin.ignore();
                            // getline(cin,address);
                            // cout << "\nEnter from date (dd-mm-yy): ";
                            // cin >> date;
                            // int i = 0;
                            // for(auto& h : hotelList){
                            //     if(h.getHotelAddress() == address){
                            //         i++; 
                            //         cout << "\n\t" << i << " - "; h.printHotel();
                            //         hotelMap[i] = h;                                      
                            //     }
                            // }
                            // cout << "\nEnter number in range 1 - " << i << " : ";
                            // int check; cin >> check;
                            // float hotel_cost;
                            // for(auto& m : hotelMap){
                            //     if(m.first == check){
                            //         trip.setPlace(m.second);
                            //         hotel_cost = m.second.getRoomPrice();
                            //         break;
                            //     }
                            // }

                            // Transport
                            // string from,to,day;
                            // cout << "\nEnter from: ";
                            // cin.ignore();
                            // getline(cin,from);
                            // cout << "\nEnter from date (dd-mm-yy): ";
                            // cin >> day;
                            // cout << "\nEnter to: ";
                            // cin.ignore();
                            // getline(cin,to);
                            // int j = 0;
                            // for(auto& t : transportList){
                            //     if(t.getDeparturePlace() == from && t.getDestination() == to){
                            //         j++;
                            //         cout << "\n\t" << j << " - "; t.printTransport();                                   
                            //         transportMap[j] = t;                                    
                            //     }
                            // }
                            // cout << "\nEnter number in range 1 - " << j << " : ";
                            // int check1; cin >> check1;
                            // float transport_cost;
                            // for(auto& m : transportMap){
                            //     if(m.first == check1){
                            //         trip.setTransportType(m.second);
                            //         transport_cost = m.second.getTicketPrice();
                            //         break;
                            //     }
                            // }
                            // float trip_cost;
                            // trip_cost = (hotel_cost + transport_cost) * numPeople;
                            // trip.setTripCost(trip_cost);
                            //
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
                        else if(n2 == 3){
                            for(auto& trip : tour){
                                trip.printTrip();
                            }
                        }
                        else if(n2 == 4){

                        }
                        else if(n2 == 5){
                            int cancel;
                            do{
                                cout << "\n1: Cancel trip";
                                cout << "\n0: Done";
                                cout << "\nEnter number in range (0 - 1): ";
                                cin >> cancel;
                                if(cancel == 1){
                                    cout << "\n\tEnter trip you want to cancel (1 - " << tripList.size() << "): ";
                                    int cancel_trip;
                                    cin >> cancel_trip;
                                    tripList.erase(tripList.begin() + cancel_trip - 1);
                                }
                            }while(cancel != 0);
                        }
                    }
                    while(n2!=0);
                    booKing[loginName] = tour;
                }
            }
        }
        else if(n == 2){
            string user_name,pass,name,addr;
            vector<string> signIn;
            cout << "\nEnter your username: ";
            cin.ignore();
            getline(cin,user_name);
            //cin >> username;
            cout << "\nEnter your password: ";
            getline(cin,pass);
            //cin >> password;
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
            //saveDataToText.insert(pair<string,string>(username, password));           
            cout << "\n\tUser Account Sign up Successfully\n\n";
        }
        else if(n == 3){
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
        else if(n == 4){
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
        else if(n == 5){
            arrangeTrip(tripList);
        }
        else if(n == 6){
            
        }

    }while (n!=0);

// Back-up data username, password to text file
saveUserInformationToTextFile("userData.txt",userList);
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
    //cout << "\n\t" << str1;
    cout << "\nEnter to: ";
    //cin.ignore();
    getline(cin,str2);
    //cout << "\n\t" << str2;
    cout << "\nEnter from Date: ";
    //cin.ignore();
    getline(cin,str3);
    //cout << "\n\t" << str3;
    cout << "\nEnter to Date: ";
    //cin.ignore();
    getline(cin,str4);
    //cout << "\n\t" << str4;
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