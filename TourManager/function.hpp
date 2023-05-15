#ifndef __FUNCTION__
#define __FUNCTION__

#include "Header.hpp"
#include "account.hpp"

// const string adminAccountName = "admin";
// const string adminAccountPassword = "111";
vector<Trip> read(const string& fileName);
void SaveTourToTextFile(const string &filename, const vector<Trip> &trip);
// Template Delete function
template <class T>
void DeleteElementInVector(vector<T>& type, string s){
    if(type.empty()){
        cout << "\n\tNO DATA";
    }
    else{
        cout << "\nWhat " << s << " do you want to delete? ";
        int index; 
        do{
            cout << "\nEnter number in range (1 - " << type.size() << "): ";
            cin >> index;
        }
        while(index < 0 || index > type.size());
        type.erase(type.begin() + index - 1);
        cout << "\n\t -> Delete successful!";
    }     
}
//
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
bool increase(Trip a, Trip b);
bool decrease(Trip a, Trip b);
void arrangeTrip(vector<Trip>& trip);
// save, read from txt file
vector<User> readUserInformationFromTextFile(const string& fileName);
vector<Transport> readTransportInformationFromTextFile(const string& fileName);
vector<Hotel> readHotelInformationFromTextFile(const string& fileName);
vector<Trip> readTourInformationFromTextFile(const string& fileName);
void SaveUserInformationToTextFile(const string &filename, const vector<User> &user);
void SaveTransportToTextFile(const string &filename, const vector<Transport> &transport);
void SaveHotelToTextFile(const string &filename, const vector<Hotel> &hotel);
// Login
    // User
void AddTrip(Trip& trip);
Hotel AddHotel(vector<Hotel>& hotelList);
Transport AddTransport(vector<Transport>& transportList);
// void DeleteTransport(vector<Transport>& transportList);
// void DeleteHotel(vector<Hotel>& hotelList);


void EditPersonalInformation(vector<User>& userList,string& loginName, string& loginPassword);
void ViewTourInformation(vector<Trip>& tour);
void EditTourInformation(vector<Hotel>& hotelList, vector<Transport>& transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);
// void AddTourFromKeyboard(vector<Hotel>& HOTEL, vector<Transport>& TRANSPORT, vector<Hotel>& hotelList, vector<Transport> transportList, vector<Trip>& tour, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);
Trip AddTourFromKeyboard(vector<Hotel>& hotelList, vector<Transport>& transportList, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);
Trip AddAvailableTour(vector<Trip>& tripList, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);
void AddTourInformation(vector<Trip>& tour, vector<Trip>& tripList, vector<Hotel>& hotelList, vector<Transport>& transportList, vector<vector<Hotel>>& hotelLogin, vector<vector<Transport>>& transportLogin);


// Tính tiền chuyến đi
float Payment(vector<Hotel>& HOTEL, vector<Transport>& TRANSPORT);
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
void AdminManageService(vector<Hotel>& hotelList, vector<Transport>& transportList);

// Sign Up
void SignUp(vector<User>& userList);
// Search Room
void SearchRoomByLocation(vector<Hotel>& hotelList);
// Search Transport
void SearchTransportByLocation(vector<Transport>& transportList);



#endif