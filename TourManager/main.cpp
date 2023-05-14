#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\trip.hpp"
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\account.hpp"
using namespace std;
const string adminAccountName = "admin";
const string adminAccountPassword = "111";
void ShowTransport(vector<Transport> &transport);
void ShowHotel(vector<Hotel> &hotel);
// Chuẩn hóa dữ liệu nhập vào từ bàn phím
string NormalizeString(const string& str);
// Check điều kiện password
bool CheckPassword(string password);
// Check tài khoản username trùng
bool CheckUsername(string username,vector<User>& userList);
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
vector<Trip> readTourInformationFromTextFile(const string& fileName);
void saveUserInformationToTextFile(const string &filename, const vector<User> &user);
void SaveTransportToTextFile(const string &filename, const vector<Transport> &transport);
void SaveHotelToTextFile(const string &filename, const vector<Hotel> &hotel);
// Login
    // User
void AddTrip(Trip& trip);
Hotel AddHotel(vector<Hotel>& hotelList);
Transport AddTransport(vector<Transport> transportList);
void DeleteTransport(vector<Transport> transportList);
void DeleteHotel(vector<Hotel>& hotelList);


void EditPersonalInformation(vector<User>& userList,string& loginName, string& loginPassword);
void ViewTourInformation(vector<Trip>& tour);
void EditTourInformation(vector<Hotel>& hotelList, vector<Transport> transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);
void AddTourInformation(vector<Hotel>& HOTEL, vector<Transport>& TRANSPORT, vector<Hotel>& hotelList, vector<Transport> transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);

// Tính tiền chuyến đi
float Payment(vector<Hotel>& HOTEL, vector<Transport> TRANSPORT);
//
void CancelTourHandles(vector<Trip>& tour);

    // Admin
        // 1
void ViewListUserAccount(vector<User>& userList);
void DeleteUserAccount(map<string,vector<Trip>>& booKing, vector<User>& userList);
void EditUserAccount(vector<User>& userList);
void AdminManageUserAccount(map<string,vector<Trip>>& booKing, vector<User>& userList);

        // 2
void AddNewHotel(vector<Hotel>& hotelList);
void AddNewTransport(vector<Transport>& transportList);
void AdminManageTransport(vector<Transport>& transportList);
void AdminManageHotel(vector<Hotel>& hotelList);
void AdminManageService(vector<Hotel>& hotelList, vector<Transport> transportList);

// Sign Up
void SignUp(vector<User>& userList);
// Search Room
void SearchRoomByLocation(vector<Hotel>& hotelList);
// Search Transport
void SearchTransportByLocation(vector<Transport>& transportList);

int main(){
    //user
    vector<User> userList = readUserInformationFromTextFile("userData.txt");
    // Trip
    vector<Trip> tripList = readTourInformationFromTextFile("tour.txt");
    map<string,vector<Trip>> booKing;
    // Transport
    vector<Transport> transportList = readTransportInformationFromTextFile("transport.txt");
    // Hotel
    vector<Hotel> hotelList = readHotelInformationFromTextFile("hotel.txt");

    int n = -1;
    do{
        //system("cls");
        mainMenu();
        cin >> n;
        if(cin.fail()){
            n = -1;
            cin.clear();
            cin.ignore();
        }
        if(n == 1){
            string loginName, loginPassword;
            cout << "\nEnter username: "; cin >> loginName;
            cout << "\nEnter password: "; cin >> loginPassword;
            // ADMIN
            if(loginName == adminAccountName && loginPassword == adminAccountPassword){
                int n4;
                do{
                    AdminMenu();
                    cin >> n4;
                    if(n4 == 1){AdminManageUserAccount(booKing,userList);}                   
                    else if(n4 == 2){AdminManageService(hotelList,transportList);}
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
            // USER
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
                    vector<vector<Hotel>> hotelLogin;
                    vector<vector<Transport>> transportLogin;
                    int n2; 
                    do{
                        UserMenu();
                        cin >> n2;
                        vector<Hotel> HOTEL;
                        vector<Transport> TRANSPORT;
                        if(n2 == 0){break;}
                        else if(n2 == 1){AddTourInformation(HOTEL,TRANSPORT,hotelList,transportList,tour,hotelLogin,transportLogin);}
                        else if(n2 == 2){EditPersonalInformation(userList,loginName,loginPassword);}
                        else if(n2 == 3){ViewTourInformation(tour);}
                        else if(n2 == 4){EditTourInformation(hotelList,transportList,tour,hotelLogin,transportLogin);}
                        else if(n2 == 5){CancelTourHandles(tour);}
                    }
                    while(n2!=0);
                    booKing[loginName] = tour;
                }
            }
        }
        else if(n == 2){SignUp(userList);}
        else if(n == 3){SearchRoomByLocation(hotelList);}
        else if(n == 4){SearchTransportByLocation(transportList);}
        else if(n == 5){ViewTourInformation(tripList);}
        else if(n == 6){arrangeTrip(tripList);}
        else if(n == 7){
            
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
    cout << "\n\t7: Arrange Trip By Time";
    cout << "\n\t6: Arrange Trip By Cost";
    cout << "\n\t5: List Tour Available";
    cout << "\n\t4: Search Transport By Location";
    cout << "\n\t3: Search Room By Location";   
    cout << "\n\t2: Sign up";
    cout << "\n\t1: Log in";
    cout << "\n\t0: Exit";
    cout << "\n\nEnter number in range 0 - 6: "; 
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
        cout << "\nTour arrange By Cost: ";
        cout << "\n2: Decreasing";
        cout << "\n1: Increasing";
        cout << "\n0: Done";
        cout << "\nEnter number in range 0 - 2: ";
        cin >> n;
        if(n == 1){
            sort(trip.begin(), trip.end(), increase);
            cout << "\nTour arrange increasing: ";
        }
        else if(
            n == 2){sort(trip.begin(), trip.end(), decrease);
            cout << "\nTour arrange decreasing: ";
        }
        ViewTourInformation(trip);
    }
    while(n != 0);
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
            user.setName(NormalizeString(s[2]));
            user.setAge(stoi(s[3]));
            user.setAddress(NormalizeString(s[4]));
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
            transport_.setTransportBrand(NormalizeString(s[0]));
            transport_.setTransportName(NormalizeString(s[1]));
            transport_.setDeparturePlace(NormalizeString(s[2]));
            transport_.setDestination(NormalizeString(s[3]));
            transport_.setDepartureDay(NormalizeString(s[4]));
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
            hotel_.setHotelName(NormalizeString(s[0]));
            hotel_.setHotelAddress(NormalizeString(s[1]));
            hotel_.setRoomType(NormalizeString(s[2]));
            hotel_.setStartDay(NormalizeString(s[3]));
            hotel_.setRoomPrice(stof(s[4]));
            x.push_back(hotel_);
        }
        file.close();
    }
    return x;
}
vector<Trip> readTourInformationFromTextFile(const string& fileName){
    vector<Trip> x;
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
            Trip tour;
            vector<Transport> transport;
            Transport transport_;
            transport_.setTransportBrand(NormalizeString(s[0]));
            transport_.setTransportName(NormalizeString(s[1]));
            transport_.setDeparturePlace(NormalizeString(s[2]));
            transport_.setDestination(NormalizeString(s[3]));
            transport_.setDepartureDay(NormalizeString(s[4]));
            transport_.setTicketPrice(stof(s[5]));
            transport.push_back(transport_);

            vector<Hotel> hotel;
            Hotel hotel_;
            hotel_.setHotelName(NormalizeString(s[6]));
            hotel_.setHotelAddress(NormalizeString(s[7]));
            hotel_.setRoomType(NormalizeString(s[8]));
            hotel_.setStartDay(NormalizeString(s[9]));
            hotel_.setRoomPrice(stof(s[10]));
            hotel.push_back(hotel_);

            tour.setTransportType(transport);
            tour.setPlace(hotel);
            tour.setFromDate(NormalizeString(s[11]));
            tour.setToDate(NormalizeString(s[12]));
            tour.setStartLocation(NormalizeString(s[13]));
            tour.setEndLocation(NormalizeString(s[14]));
            tour.setNumberOfPeople(stoi(s[15]));
            tour.setTripCost(stof(s[16]));
            x.push_back(tour);
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
    trip.setStartLocation(NormalizeString(str1));
    trip.setEndLocation(NormalizeString(str2));
    trip.setFromDate(NormalizeString(str3));
    trip.setToDate(NormalizeString(str4));
    trip.setNumberOfPeople(numPeople);
}
Hotel AddHotel(vector<Hotel>& hotelList){
    Hotel y;
    vector<Hotel> x;
    string address,date;
    int i = 0;
    do{
        
        cout << "\nEnter hotel address: ";
        fflush(stdin);
        getline(cin,address);
        // cout << "\nEnter from date (dd-mm-yy): ";
        // cin >> date;       

        for(auto& h : hotelList){
            if(h.getHotelAddress() == NormalizeString(address)){
                x.push_back(h);
                i++;
                cout << "\n\t" << i << " - "; h.printHotel();
            }
        }
        if(x.empty()){
            cout << "\nDo not find hotel in " << address << ", Please enter again: ";
        }
        else{
            cout << "\nEnter number in range 1 - " << i << " : ";
            int id; cin >> id;    
            y = x[id-1];
        }               
    }
    while(x.empty());
    return y;
}
Transport AddTransport(vector<Transport> transportList){
    Transport y;
    vector<Transport> x;
    string from,to,day;
    int i = 0;
    do{
        cout << "\nEnter from: ";
        fflush(stdin);
        getline(cin,from);
        // cout << "\nEnter from date (dd-mm-yy): ";
        // cin >> day;
        cout << "\nEnter to: ";
        getline(cin,to);
        for(auto& t : transportList){
            if(t.getDeparturePlace() == NormalizeString(from) && t.getDestination() == NormalizeString(to)){
                x.push_back(t);
                i++;
                cout << "\n\t" << i << " - "; t.printTransport();
            }
        }
        if(x.empty()){
            cout << "\nDo not find transport from " << from << " to " << to << ", Please enter again: ";
        }
        else{
            cout << "\nEnter number in range 1 - " << i << " : ";
            int id; cin >> id;    
            y = x[id-1];
        } 
    }
    while(x.empty());
    return y;
}
void DeleteTransport(vector<Transport> transportList){
    if(transportList.empty()){
        cout << "\n\tNO DATA";
    }
    else{
        cout << "\nWhat transport do you want to delete? ";
        int index; 
        do{
            cout << "\nEnter number in range (1 - " << transportList.size() << "): ";
            cin >> index;
        }
        while(index < 0 || index > transportList.size());
        transportList.erase(transportList.begin() + index - 1);
        cout << "\n\t -> Delete successful!";
    }     
}
void DeleteHotel(vector<Hotel>& hotelList){
    if(hotelList.empty()){
        cout << "\n\tNO DATA";
    }
    else{
        cout << "\nWhat hotel do you want to delete? ";
        int index; 
        do{
            cout << "\nEnter number in range (1 - " << hotelList.size() << "): ";
            cin >> index;
        }
        while(index < 0 || index > hotelList.size());
        hotelList.erase(hotelList.begin() + index - 1);
        cout << "\n\t -> Delete successful!";
    }   
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
            userList[index].setName(NormalizeString(fullName));
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
            userList[index].setAddress(NormalizeString(address_));
            cout << "\n\t->New address edited!";
        }
        else if(n3 == 4){
            cout << "\nEnter new password: ";
            string pass_;
            cin.ignore();
            getline(cin,pass_);
            while(CheckPassword(pass_) == false){
                cout << "\nPassword must have more than 6 characters, uppercase, lowercase! Enter again: ";
                cout << "\nEnter new password: ";
                cin >> pass_;
            }
            userList[index].setAccountPassword(pass_);
            cout << "\n\t->New Password edited!";
        }                                
    }while(n3 != 0);
}
void AddTourInformation(vector<Hotel>& HOTEL, vector<Transport>& TRANSPORT, vector<Hotel>& hotelList, vector<Transport> transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin){
    Trip trip;
    AddTrip(trip);
    int n5;
    do{
        cout << "\nEnter Service: ";
        cout << "\n\t1: Add Hotel";
        cout << "\n\t2: Add Transport";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range (0 - 2): ";
        cin >> n5;
        if(n5 == 1){
            HOTEL.push_back(AddHotel(hotelList));
        }
        else if( n5 == 2){
            TRANSPORT.push_back(AddTransport(transportList));
        }
    }
    while(n5 != 0);
    hotelLogin.push_back(HOTEL);
    transportLogin.push_back(TRANSPORT);
    trip.setPlace(HOTEL);
    trip.setTransportType(TRANSPORT);
    trip.setTripCost(Payment(HOTEL,TRANSPORT)*trip.getNumberOfPeople());
    tour.push_back(trip);
}
void ViewTourInformation(vector<Trip>& tour){
    if(tour.empty()){
        cout << "\nNO DATA";
    }
    else{
        cout << "\n------------List Tour------------\n";
        for(auto& trip : tour){
            trip.printTrip();
        }
    }
}
void EditTourInformation(vector<Hotel>& hotelList, vector<Transport> transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin){
    if(tour.empty()){
        cout << "\nNO DATA";
    }
    else{
        cout << "\nWhat trip number do you want to edit? ";
        int index; 
        do{
            cout << "\nEnter number in range (1 - " << tour.size() << "): ";
            cin >> index;
        }
        while(index < 0 || index > tour.size());
        int n3;
        do{
            cout << "\nWhat information do you want to edit? ";
            cout << "\n\t1: Transport";
            cout << "\n\t2: Hotel";
            cout << "\n\t3: Start Day";
            cout << "\n\t4: Come Back Day";
            cout << "\n\t5: Start Place";
            cout << "\n\t6: Destination";
            cout << "\n\t7: Number of people";
            cout << "\n\t0: Done";
            cout << "\nEnter number in range (0-7): ";
            cin >> n3;                                    
            if(n3 == 1){
                cout << "\nThis is your list transport you booked: ";
                ShowTransport(transportLogin[index-1]);
                int n4;
                do{
                    cout << "\nWhat do you want ?";
                    cout << "\n\t1: Add new";
                    cout << "\n\t2: Edit";
                    cout << "\n\t3: Delete";
                    cout << "\n\t0: Done";
                    cout << "\nEnter number in range (0-3): ";
                    cin >> n4;
                    if(n4 == 1){
                        cout << "\n\tAdd new Transport: ";
                        transportLogin[index-1].push_back(AddTransport(transportList));
                        cout << "\n\t -> Add successful!!";
                    }
                    else if(n4 == 2){
                        cout << "\nWhat transport number do you want to edit? ";
                        int id; 
                        do{
                            cout << "\nEnter number in range (1 - " << transportLogin[index-1].size() << "): ";
                            cin >> id;
                        }
                        while(id < 0 || id > transportLogin[index-1].size());
                        cout << "\n\tEnter new Transport: ";
                        transportLogin[index-1][id-1] = AddTransport(transportList);
                        cout << "\n\t -> Edit successful!!";
                    }
                    else if(n4 == 3){DeleteTransport(transportLogin[index-1]);}
                    tour[index-1].setTransportType(transportLogin[index-1]);
                }
                while(n4 != 0);                                
            }                                        
            else if(n3 == 2){
                cout << "\nThis is your list hotel you booked: ";
                ShowHotel(hotelLogin[index-1]);
                int n4;
                do{
                    cout << "\nWhat do you want ?";
                    cout << "\n\t1: Add new";
                    cout << "\n\t2: Edit";
                    cout << "\n\t3: Delete";
                    cout << "\n\t0: Done";
                    cout << "\nEnter number in range (0-3): ";
                    cin >> n4;
                    if(n4 == 1){
                        cout << "\n\tAdd new Transport: ";
                        hotelLogin[index-1].push_back(AddHotel(hotelList));
                        cout << "\n\t -> Add successful!!";
                    }
                    else if(n4 == 2){
                        cout << "\nWhat hotel number do you want to edit? ";
                        int id; 
                        do{
                            cout << "\nEnter number in range (1 - " << hotelLogin[index-1].size() << "): ";
                            cin >> id;
                        }
                        while(id < 0 || id > hotelLogin[index-1].size());
                        cout << "\n\tEnter new Hotel: ";
                        hotelLogin[index-1][id-1] = AddHotel(hotelList);
                        cout << "\n\t -> Edit successful!!";
                    }
                    else if(n4 == 3){DeleteHotel(hotelLogin[index-1]);}
                    tour[index-1].setPlace(hotelLogin[index-1]);
                }
                while(n4 != 0);
            }
            else if(n3 == 3){
                cout << "\nEnter new Start Day: ";
                string s;
                cin.ignore();
                getline(cin,s);
                tour[index-1].setFromDate(NormalizeString(s));
            }
            else if(n3 == 4){
                cout << "\nEnter new Come Back Day: ";
                string s;
                cin.ignore();
                getline(cin,s);
                tour[index-1].setToDate(NormalizeString(s));
            }
            else if(n3 == 5){
                cout << "\nEnter new Start Place: ";
                string s;
                cin.ignore();
                getline(cin,s);
                tour[index-1].setStartLocation(NormalizeString(s));
            }
            else if(n3 == 6){
                cout << "\nEnter new Destination: ";
                string s;
                cin.ignore();
                getline(cin,s);
                tour[index-1].setEndLocation(NormalizeString(s));
            }
            else if(n3 == 7){
                cout << "\nEnter new Number of people: ";
                int num; cin >> num;
                tour[index - 1].setNumberOfPeople(num);
            }
        }
        while(n3 != 0);
        tour[index-1].setTripCost(Payment(hotelLogin[index-1],transportLogin[index-1])*tour[index-1].getNumberOfPeople());
    }
}
void CancelTourHandles(vector<Trip>& tour){
    int cancel;
    if(tour.empty()){
        cout << "\nNO DATA ABOUT TOUR!!";
    }
    else{
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
}

void SignUp(vector<User>& userList){
    string user_name,pass,name,addr;
    cout << "\nEnter your username: ";
    cin >> user_name;
    while(CheckUsername(user_name,userList) == false){
        cout << "\nUsername had existed! Enter again: ";
        cout << "\nEnter your username: ";
        cin >> user_name;
    }
    cout << "\nEnter your password: ";
    cin >> pass;
    while(CheckPassword(pass) == false){
        cout << "\nPassword must have more than 6 characters, uppercase, lowercase! Enter again: ";
        cout << "\nEnter your password: ";
        cin >> pass;
    }
    cout << "\nEnter your full name: ";
    cin.ignore();
    getline(cin,name);
    cout << "\nEnter your age: ";
    int AGE; cin >> AGE;
    cout << "\nEnter your address: ";
    cin.ignore();
    getline(cin,addr);
    User user;
    user.setAccountName(user_name);
    user.setAccountPassword(pass);
    user.setName(NormalizeString(name));
    user.setAge(AGE);
    user.setAddress(NormalizeString(addr));
    userList.push_back(user);          
    cout << "\n\tUser Account Sign up Successfully\n\n";
}
void SearchRoomByLocation(vector<Hotel>& hotelList){
    cout << "\nWhere do you want to find hotel? ";
    string find_hotel;
    cin.ignore();
    getline(cin,find_hotel);
    int i = 0;
    for(auto& h : hotelList){
        if(h.getHotelAddress() == NormalizeString(find_hotel)){
            i++;
            cout << "\n\t" << i << " - "; h.printHotel();
        }
    }
}
void SearchTransportByLocation(vector<Transport>& transportList){
    cout << "\nWhere do you want to find transport? ";
    string find_transport;
    cin.ignore();
    getline(cin,find_transport);
    int i = 0;
    for(auto& t : transportList){
        if(t.getDeparturePlace() == NormalizeString(find_transport)){
            i++;
            cout << "\n\t" << i << " - "; t.printTransport();
        }
    }
}

void ViewListUserAccount(vector<User>& userList){
    cout << "\n------------List User Account------------\n";
    for(int i = 0; i < userList.size(); ++i){
        cout << "\n\tAccount " << i+1 << ": " << userList[i].getAccountName();
    }
}
void DeleteUserAccount(map<string,vector<Trip>>& booKing, vector<User>& userList){
    cout << "\n------------Delete User Account------------";
    cout << "\nWhich account do you want to delete? ";
    cout << "\nEnter username: ";
    string user_name;
    cin >> user_name;
    int index = -1;
    if(booKing.empty()){    
        for(int i = 0; i < userList.size(); ++i){
            if(userList[i].getAccountName() == user_name){
                index = i;
                break;
            }
        }
        if(index == -1){
            cout << "\nDo not exist account " << user_name << " !!";
        }
        else{
            userList.erase(userList.begin() + index);
            cout << "\n\t->Account " << user_name << " deleted!";
        }
    }
    else{
        bool check1 = false;
        for(auto& m : booKing){
            if(m.first == user_name){
                check1 = true;
                booKing.erase(user_name);
                break;
            } 
        }
        if(check1 == false){
            cout << "\nDo not exist account " << user_name << " !!";
        }
        else{
            cout << "\n\t->Account" << user_name << " deleted!";
        }
    }

}
void EditUserAccount(vector<User>& userList){
    cout << "\n------------Edit User Account------------";
    cout << "\nWhich account do you want to edit? ";
    cout << "\nEnter username: ";
    string acc;
    cin >> acc;
    int id = -1;
    for(int i = 0; i < userList.size();  ++i){
        if(acc == userList[i].getAccountName()){
            id = i;
            break;
        }
    }
    if(id == -1){
        cout << "\nDo not exist account " << acc << " !!" << endl;
    }  
    else{
        string new_acc;
        cout << "\nEnter new account username: ";
        cin >> new_acc;
        userList[id].setAccountName(new_acc);
        cout << "\n\t->Account edited!";
    }
}
void AdminManageUserAccount(map<string,vector<Trip>>& booKing, vector<User>& userList){
    int n5;
    do{
        cout << "\n------------------------------------------------\n";
        cout << "\n\t***** User Account *****";
        cout << "\n\t1: View List User Account";
        cout << "\n\t2: Edit User Account";
        cout << "\n\t3: Delete User Account";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range 0 - 3: ";
        cin >> n5;
        if(n5 == 1){ViewListUserAccount(userList);}
        else if(n5 == 2){EditUserAccount(userList);}
        else if(n5 == 3){DeleteUserAccount(booKing,userList);}       
    }while(n5 != 0);  
}

void AddNewHotel(vector<Hotel>& hotelList){
    cout << "\n\tAdd new Hotel: ";
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
    // x.setHotelName(hotel_name);
    x.setHotelName(NormalizeString(hotel_name));
    x.setHotelAddress(NormalizeString(address));
    x.setRoomType(NormalizeString(room_type));
    x.setStartDay(NormalizeString(date));
    x.setRoomPrice(price);
    hotelList.push_back(x);
    cout << "\n\t -> New hotel had been added !!";
}
void AddNewTransport(vector<Transport>& transportList){
    cout << "\n\tAdd new Transport: ";
    string transportName,transportBrand,departureDay,departurePlace,destination;
    float ticketPrice;
    Transport x;
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
    x.setTransportBrand(NormalizeString(transportBrand));
    x.setTransportName(NormalizeString(transportName));
    x.setDepartureDay(NormalizeString(departureDay));
    x.setDeparturePlace(NormalizeString(departurePlace));
    x.setDestination(NormalizeString(destination));
    x.setTicketPrice(ticketPrice);
    transportList.push_back(x);
    cout << "\n\t -> New transport had been added !!";
}
void AdminManageTransport(vector<Transport>& transportList){
    int n6;
    do{
        cout << "\n------------------------------------------------\n";
        cout << "\n\t1: View Transport Information";
        cout << "\n\t2: Add Transport ";
        cout << "\n\t3: Delete Transport ";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range 0 - 3: ";
        cin >> n6;
        if(n6 == 1){ShowTransport(transportList);}
        else if(n6 == 2){AddNewTransport(transportList);}
        else if(n6 == 3){DeleteTransport(transportList);}     
    }
    while(n6 != 0);
}
void AdminManageHotel(vector<Hotel>& hotelList){
    int n6;
    do{
        cout << "\n------------------------------------------------\n";
        cout << "\n\t1: View Hotel Information";
        cout << "\n\t2: Add New Hotel";
        cout << "\n\t3: Delete Hotel";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range 0 - 3: ";
        cin >> n6;
        if(n6 == 1){ShowHotel(hotelList);}
        else if(n6 == 2){AddNewHotel(hotelList);}
        else if(n6 == 3){DeleteHotel(hotelList);
            // cout << "\nWhat hotel do you want to delete? ";
            // int index; 
            // do{
            //     cout << "\nEnter number in range (1 - " << hotelList.size() << "): ";
            //     cin >> index;
            // }
            // while(index < 0 || index > hotelList.size());
            // hotelList.erase(hotelList.begin() + index - 1);
            // cout << "\n\t -> Delete successful!";
        }                                         
    }  
    while(n6 != 0);
}
void AdminManageService(vector<Hotel>& hotelList, vector<Transport> transportList){
    int n5;
    do{
        cout << "\n*** Service Information ***";
        cout << "\n\t1: Hotel Information";
        cout << "\n\t2: Transport Information";
        cout << "\n\t0: Done";
        cout << "\nEnter number in range 0 - 2: ";
        cin >> n5;
        if(n5 == 1){AdminManageHotel(hotelList);}
        else if(n5 == 2){AdminManageTransport(transportList);}      
    }
    while(n5 != 0);
}

string NormalizeString(const string& str) {
    string result;
    bool inWord = false;
    for (char c : str) {
        if (isspace(c)) {
            if (inWord) {
                inWord = false;
                result += ' ';
            }
        } else {
            if (!inWord) {
                inWord = true;
                result += toupper(c);
            } else {
                result += tolower(c);
            }
        }
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}
bool CheckPassword(string password) {
    bool hasLower = false, hasUpper = false, hasDigit = false;
    if (password.length() < 6) {
        return false;
    }
    for (char ch : password) {
        if (islower(ch)) {
            hasLower = true;
        }
        if (isupper(ch)) {
            hasUpper = true;
        }
        if (isdigit(ch)) {
            hasDigit = true;
        }
    }
    return hasLower && hasUpper && hasDigit;
}
bool CheckUsername(string username,vector<User>& userList){
    bool check = false;
    for(auto& u : userList){
        if(u.getAccountName() == username){
            check = true;
            break;
        }
    }
    if(check == true){
        return false;
    }
    else{
        return true;
    }
}
void ShowTransport(vector<Transport> &transport){
    int i = 0;
    cout << "\n------------List Transport------------\n";
    for(auto& t : transport){
        i++;
       cout << "\n\t" << i << " - "; t.printTransport();
    }
}
void ShowHotel(vector<Hotel> &hotel){
    int i = 0;
    cout << "\n------------List Hotel------------\n";
    for(auto& t : hotel){
        i++;
       cout << "\n\t" << i << " - "; t.printHotel();
    }    
}
float Payment(vector<Hotel>& HOTEL, vector<Transport> TRANSPORT){
    float trip_cost;
    float hotel_cost = 0;
    float transport_cost = 0;
    for(auto& h : HOTEL){
        hotel_cost += h.getRoomPrice();
    }
    for(auto& t : TRANSPORT){
        transport_cost += t.getTicketPrice();
    }
    trip_cost = hotel_cost + transport_cost;
    return trip_cost;
}



