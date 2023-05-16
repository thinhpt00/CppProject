#include "function.hpp"
const string adminAccountName = "admin";
const string adminAccountPassword = "111";

int main(){    
    vector<Transport> transportList = readTransportInformationFromTextFile("Data//transport.txt");
    vector<Hotel> hotelList = readHotelInformationFromTextFile("Data//hotel.txt");
    vector<User> userList = readUserInformationFromTextFile("Data//userData.txt");
    vector<Trip> tripList = ReadTourInformationFromTextFile("Data//tour.txt");
    map<string,vector<Trip>> booKing;
    vector<Account> accountList;

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
                int n1;
                do{
                    AdminMenu();
                    cin >> n1;
                    if(n1 == 1){AdminManageUserAccount(accountList,userList);}                   
                    else if(n1 == 2){AdminManageService(hotelList,transportList);}
                    else if(n1 == 3){AdminManageSystemData(userList,transportList,hotelList,tripList,accountList);}
                }
                while(n1 != 0);                
            }
            // USER
            else{
                Account acc;
                bool check = false;
                for(auto& u : userList){
                    if(loginName == u.getAccountName() && loginPassword == u.getAccountPassword() ){
                        acc.setUserAccount(u);
                        check = true;
                        break;
                    }
                }
                if(check == false){
                    cout << "\nLogin failed!";
                }
                else{
                    // vector<Trip> tour;
                    // vector<vector<Hotel>> hotelLogin;
                    // vector<vector<Transport>> transportLogin;
                    int n2; 
                    do{
                        UserMenu();
                        cin >> n2;
                        if(n2 == 1){
                            AddTourInformation(acc,tripList,hotelList,transportList);
                            accountList.push_back(acc);
                            // AddTourInformation(tour,tripList,hotelList,transportList,hotelLogin,transportLogin);
                        }
                        else if(n2 == 2){EditPersonalInformation(userList,loginName,loginPassword);}
                        else if(n2 == 3){ViewTourInformation(acc.getTourOfCLient());}
                        else if(n2 == 4){
                            EditTourInformation(acc,hotelList,transportList);
                            // EditTourInformation(hotelList,transportList,tour,hotelLogin,transportLogin);
                        }
                        else if(n2 == 5){DeleteElementInVector<Trip>(move(acc.getTourOfCLient()),"tour");}
                        SaveAccountToTextFile("BackUpData//BackUpAccount.txt",accountList);
                    }
                    while(n2!=0);
                    // acc.setTourOfCLient(tour);
                    // accountList.push_back(acc);
                    SaveAccountToTextFile("BackUpData//BackUpAccount.txt",accountList);
                    // booKing[loginName] = tour;
                }
            }
        }
        else if(n == 2){SignUp(userList);}
        else if(n == 3){SearchRoomByLocation(hotelList);}
        else if(n == 4){SearchTransportByLocation(transportList);}
        else if(n == 5){ViewTourInformation(tripList);}
        else if(n == 6){arrangeTrip(tripList);}

    }while (n!=0);

// Back-up data username, password to text file
    // SaveUserInformationToTextFile("Data//userData.txt",userList);
    // SaveTransportToTextFile("Data//transport.txt", transportList);
    // SaveHotelToTextFile("Data//hotel.txt", hotelList);
    // SaveTourToTextFile("Data//tour.txt", tripList);
    // SaveAccountToTextFile("t.txt",accountList);
/////////////
    return 0;
}





