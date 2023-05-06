

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\hotel.hpp"
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\transport.hpp"

using namespace std;
const string adminAccountName = "admin";
const string adminAccountPassword = "111";

void mainMenu(){
    cout << "Menu:";   
    cout << "\n\t2: Sign up";
    cout << "\n\t1: Log in";
    cout << "\n\t0: Exit";
}
int main(){
    // Transport
    vector<Transport> transportList;
    map<int,Transport> transportMap;
    ifstream transportFile("transport.txt");
    string str_transport;
    while (getline(transportFile, str_transport)){
        stringstream ss(str_transport);
        string s_1,s_2,s_3,s_4,s_5,s_6;
        ss >> s_1 >> s_2 >> s_3 >> s_4 >> s_5 >> s_6;
        Transport transport_;
        transport_.setTransportBrand(s_1);
        transport_.setTransportName(s_2);
        transport_.setDeparturePlace(s_3);
        transport_.setDestination(s_4);
        transport_.setDepartureDay(s_5);
        transport_.setTicketPrice(stof(s_6));

        transportList.push_back(transport_);
    }
    for(auto x2 : transportList){
        x2.printTransport();
    }
    // Hotel
    vector<Hotel> hotelList;
    map<int,Hotel> hotelMap;
    ifstream hotelFile("hotel.txt");
    string s;
    while (getline(hotelFile, s)){
        stringstream ss(s);
        string s1,s2,s3,s4,s5;
        ss >> s1 >> s2 >> s3 >> s4 >> s5;
        Hotel x;
        x.setHotelName(s1);
        x.setHotelAddress(s2);
        x.setRoomType(s3);
        x.setStartDay(s4);
        x.setRoomPrice(stof(s5));
        hotelList.push_back(x);
    }
    // for(auto x1 : hotelList){
    //     x1.printHotel();
    // }

    // Password, username
    map<string,string> saveDataToText;
    ifstream inputFile("signUpData.txt");
    string line;
    while (getline(inputFile, line)) {
        // Tách dữ liệu trên mỗi dòng thành các phần tử riêng biệt
        istringstream iss(line);
        string user;
        string pass;
        if (iss >> user >> pass) {
            // Lưu các phần tử vào map
            saveDataToText[user] = pass;
        }
    }
    // for(auto x : saveDataToText){
    //     cout << x.first << " - " << x.second << endl;  
    // }
    ///////////
    int n = -1;
    do{
        //system("cls");
        mainMenu();
        cout << "\n\nEnter number in range 0 - 2: "; 
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
                for(auto x : saveDataToText){
                    if(loginName == x.first && loginPassword == x.second){
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
                            //Hotel
                            string address,date;
                            cout << "\nEnter hotel address: ";
                            cin.ignore();
                            getline(cin,address);
                            cout << "\nEnter from date (dd-mm-yy): ";
                            cin >> date;
                            for(auto h : hotelList){
                                if(h.getHotelAddress() == address){
                                    int i = 1;
                                    h.printHotel();
                                    hotelMap[i] = h;
                                    i++;    
                                }
                            }
                            for(auto m : hotelMap){

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
                            for(auto t : transportList){
                                if(t.getDeparturePlace() == from && t.getDestination() == to){
                                    t.printTransport();
                                }
                            }
                        }
                    }
                    while(n2 < 0 || n2 > 5);
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
            string username, password;
            cout << "\nEnter your username: ";
            cin >> username;
            cout << "\nEnter your password: ";
            cin >> password;
            saveDataToText.insert(pair<string,string>(username, password));           
            cout << "\n\tUser Account Sign up Successfully\n\n";
        }
        // else{
        //     while(n < 0 || n > 2){
        //         cout << "Re-enter number in range 0 - 2: ";
        //         cin >> n;
        //     }
        // }
    }while (n!=0);

// Back-up data username, password to text file
    std::ofstream outFile("signUpData.txt");
    if (outFile.is_open()){
        for(auto x : saveDataToText){
            //string s = x.first + " - " + x.second;
            outFile << x.first << " " << x.second << endl;
            //cout << x.first << " - " << x.second << endl;  
        }
        outFile.close();
    }
/////////////
    return 0;
}
