#include "function.hpp"
const string adminAccountName = "admin";
const string adminAccountPassword = "111";

int main(){
    
    vector<Transport> transportList = readTransportInformationFromTextFile("Data//transport.txt");
    vector<Hotel> hotelList = readHotelInformationFromTextFile("Data//hotel.txt");
    vector<User> userList = readUserInformationFromTextFile("Data//userData.txt");
    vector<Trip> tripList = ReadTourInformationFromTextFile("Data//tour.txt");
    map<string,vector<Trip>> booKing;
    vector<Account> accountList = ReadAccountInformationFromTextFile("Data//account.txt");

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
                    if(n4 == 1){AdminManageUserAccount(accountList,userList);}                   
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
                                SaveSystemData(userList,transportList,hotelList,tripList,accountList);
                                cout << "Save System Data Successful!!";
                            }
                            else if(n5 == 2){
                                // accountList = ReadAccountInformationFromTextFile("Data//account.txt");
                                LoadSystemData(userList,transportList,hotelList,tripList,accountList);
                                cout << "Load System Data Successful!!";
                            }       
                        }
                        while(n5 != 0); 
                    }
                }while(n4 != 0);                
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
                    
                    vector<Trip> tour;
                    vector<vector<Hotel>> hotelLogin;
                    vector<vector<Transport>> transportLogin;
                    for(auto& a : accountList){
                        if(a.getUserAccount().getAccountName() == loginName){
                            tour = a.getTourOfCLient();
                        }
                    }
                    for(auto& t : tour){
                        hotelLogin.push_back(t.getPlace());
                        transportLogin.push_back(t.getTransportType());
                    }
                    int n2; 
                    do{
                        UserMenu();
                        cin >> n2;
                        if(n2 == 1){AddTourInformation(tour,tripList,hotelList,transportList,hotelLogin,transportLogin);}
                        else if(n2 == 2){EditPersonalInformation(userList,loginName,loginPassword);}
                        else if(n2 == 3){ViewTourInformation(tour);}
                        else if(n2 == 4){EditTourInformation(hotelList,transportList,tour,hotelLogin,transportLogin);}
                        else if(n2 == 5){DeleteElementInVector<Trip>(tour,"tour");}
                    }
                    while(n2!=0);
                    acc.setTourOfCLient(tour);
                    accountList.push_back(acc);
                    SaveAccountToTextFile("Data//account.txt",accountList);
                    booKing[loginName] = tour;
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





