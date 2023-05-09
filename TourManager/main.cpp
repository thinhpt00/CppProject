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

int main(){
    //user
    vector<User> userList;
    userList = readUserInformationFromTextFile("signUpData.txt");
    // for(auto& u : userList){
    //     u.printUser();
    // }

    // Trip
    vector<Trip> tripList;
    map<int,Trip> tripMap;

    // Transport
    vector<Transport> transportList;
    map<int,Transport> transportMap;
    transportList = readTransportInformationFromTextFile("transport.txt");
    // for(auto& x2 : transportList){
    //     x2.printTransport();
    // }
    // ifstream transportFile("transport.txt");
    // string str_transport;
    // while (getline(transportFile, str_transport)){
    //     stringstream ss(str_transport);
    //     string s_1,s_2,s_3,s_4,s_5,s_6;
    //     ss >> s_1 >> s_2 >> s_3 >> s_4 >> s_5 >> s_6;
    //     Transport transport_;
    //     transport_.setTransportBrand(s_1);
    //     transport_.setTransportName(s_2);
    //     transport_.setDeparturePlace(s_3);
    //     transport_.setDestination(s_4);
    //     transport_.setDepartureDay(s_5);
    //     transport_.setTicketPrice(stof(s_6));
    //     transportList.push_back(transport_);
    // }

    // Hotel
    vector<Hotel> hotelList;
    map<int,Hotel> hotelMap;
    hotelList = readHotelInformationFromTextFile("hotel.txt");
    // ifstream hotelFile("hotel.txt");
    // string s;
    // while (getline(hotelFile, s)){
    //     stringstream ss(s);
    //     string s1,s2,s3,s4,s5;
    //     ss >> s1 >> s2 >> s3 >> s4 >> s5;
    //     Hotel x;
    //     x.setHotelName(s1);
    //     x.setHotelAddress(s2);
    //     x.setRoomType(s3);
    //     x.setStartDay(s4);
    //     x.setRoomPrice(stof(s5));
    //     hotelList.push_back(x);
    // }
    // for(auto& x1 : hotelList){
    //     x1.printHotel();
    // }

    // Password, username
    // map<string,string> saveDataToText;
    // ifstream inputFile("signUpData.txt");
    // string line;
    // while (getline(inputFile, line)) {
    //     // Tách dữ liệu trên mỗi dòng thành các phần tử riêng biệt
    //     istringstream iss(line);
    //     string user;
    //     string pass;
    //     if (iss >> user >> pass) {
    //         // Lưu các phần tử vào map
    //         saveDataToText[user] = pass;
    //     }
    // }
    // for(auto& x : saveDataToText){
    //     cout << x.first << " - " << x.second << endl;  
    // }
    ///////////

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
            string loginName, loginPassword;
            cout << "\nEnter username: ";
            cin >> loginName;
            cout << "\nEnter password: ";
            cin >> loginPassword;
            if(loginName == adminAccountName && loginPassword == adminAccountPassword){
                cout << "\nHello, Admin!\nWhat do you want?";
                cout << "\n1: viewListUserAccount";
                cout << "\n2: editUserAccount";
                cout << "\n3: deleteUserAccount";
                cout << "\n4: viewServiceInformation";
                cout << "\n5: addServiceInformation";
                cout << "\n6: deleteServiceInformation";
                cout << "\n7: saveSystemData";
                cout << "\n8: loadSystemData";
                cout << "\n\nEnter number in range 1 - 8: ";
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
                    int n2; 
                    do{
                        cout << "\nHello, User!\nWhat do you want?";
                        cout << "\n1: Add Trip";
                        cout << "\n2: Edit Personal Information";
                        cout << "\n3: View Trip Information";
                        cout << "\n4: Edit Trip Information";
                        cout << "\n5: Cancel Trip Handles";
                        cout << "\n0: Done";
                        cout << "\n\nEnter number in range 0 - 5: ";
                        cin >> n2;
                        if(n2 == 0){break;}
                        else if(n2 == 1){
                            //Trip
                            Trip trip;
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

                            //Hotel
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
                                    trip.setPlace(m.second);
                                    hotel_cost = m.second.getRoomPrice();
                                    break;
                                }
                            }
                            // Transport
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
                                    trip.setTransportType(m.second);
                                    transport_cost = m.second.getTicketPrice();
                                    break;
                                }
                            }
                            float trip_cost;
                            trip_cost = (hotel_cost + transport_cost) * numPeople;
                            trip.setTripCost(trip_cost);
                            tripList.push_back(trip);
                            //
                        }
                        else if(n2 == 2){

                        }
                        else if(n2 == 3){
                            for(auto& trip : tripList){
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
                }
            }
            // cout << "\n1: User Account";
            // cout << "\n2: Admin Account";
            // cout << "\n\nEnter number in range 1 - 2: ";
            // int n1; cin >> n1;
            // if(n1 == 1){
            // }
            // else if(n1 == 2){
            //     //
            // }
            // else{
            //     //
            // }
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
saveUserInformationToTextFile("signUpData.txt",userList);
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
