// #include "function.hpp"
// const string adminAccountName = "admin";
// const string adminAccountPassword = "111";
// int main(){    
//     vector<Transport> transportList = readTransportInformationFromTextFile("Data//transport.txt");
//     vector<Hotel> hotelList = readHotelInformationFromTextFile("Data//hotel.txt");
//     vector<User> userList = readUserInformationFromTextFile("Data//userData.txt");
//     vector<Trip> tripList = ReadTourInformationFromTextFile("Data//tour.txt");
//     vector<Account> accountList = ReadAccountInformationFromTextFile("Data//account.txt");
//     int n = -1;
//     do{
//         mainMenu();
//         cin >> n;
//         if(cin.fail()){
//             n = -1;
//             cin.clear();
//             cin.ignore();
//         }
//         if(n == 1){
//             string loginName, loginPassword;
//             cout << "\nEnter username: "; cin >> loginName;
//             cout << "\nEnter password: "; cin >> loginPassword;
//             // ADMIN
//             if(loginName == adminAccountName && loginPassword == adminAccountPassword){
//                 int n1;
//                 do{
//                     AdminMenu();
//                     cin >> n1;
//                     if(n1 == 1){AdminManageUserAccount(accountList,userList);}                   
//                     else if(n1 == 2){AdminManageService(hotelList,transportList);}
//                     else if(n1 == 3){AdminManageSystemData(userList,transportList,hotelList,tripList,accountList);}
//                 }
//                 while(n1 != 0);                
//             }
//             // USER
//             else{
//                 Account acc;
//                 bool check = false;
//                 for(auto& u : userList){
//                     if(loginName == u.getAccountName() && loginPassword == u.getAccountPassword()){
//                         acc.setUserAccount(u);
//                         check = true;
//                         break;
//                     }
//                 }
//                 if(check == false){cout << "\nLogin failed!";}
//                 else{
//                     vector<Trip> tour;
//                     vector<vector<Hotel>> hotelLogin;
//                     vector<vector<Transport>> transportLogin;
//                     for(auto& a : accountList){
//                         if(a.getUserAccount().getAccountName() == loginName){
//                             tour = a.getTourOfCLient();
//                         }
//                     }
//                     for(auto& t : tour){
//                         hotelLogin.push_back(t.getPlace());
//                         transportLogin.push_back(t.getTransportType());
//                     }
//                     int n2; 
//                     do{
//                         UserMenu();
//                         cin >> n2;
//                         if(n2 == 1){AddTourInformation(tour,tripList,hotelList,transportList,hotelLogin,transportLogin);}
//                         else if(n2 == 2){EditPersonalInformation(userList,loginName,loginPassword);}
//                         else if(n2 == 3){ViewTourInformation(tour);}
//                         else if(n2 == 4){EditTourInformation(hotelList,transportList,tour,hotelLogin,transportLogin);}
//                         else if(n2 == 5){DeleteElementInVector<Trip>(tour,"tour");}
//                     }
//                     while(n2!=0);
//                     acc.setTourOfCLient(tour);
//                     accountList.push_back(acc);
//                     SaveAccountToTextFile("Data//account.txt",accountList);
//                 }
//             }
//         }
//         else if(n == 2){SignUp(userList);}
//         else if(n == 3){SearchRoomByLocation(hotelList);}
//         else if(n == 4){SearchTransportByLocation(transportList);}
//         else if(n == 5){ViewTourInformation(tripList);}
//         else if(n == 6){arrangeTrip(tripList);}
//     }
//     while (n != 0);
//     return 0;
// }





#include "function.hpp"
const string adminAccountName = "admin";
const string adminAccountPassword = "111";

int main(){    
    vector<Transport> transportList = readTransportInformationFromTextFile("Data//transport.txt");
    vector<Hotel> hotelList = readHotelInformationFromTextFile("Data//hotel.txt");
    vector<User> userList = readUserInformationFromTextFile("Data//userData.txt");
    vector<Trip> tripList = ReadTourInformationFromTextFile("Data//tour.txt");
    vector<Account> accountList = ReadAccountInformationFromTextFile("Data//account.txt");
    int n = -1;
    do{
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
                    if(loginName == u.getAccountName() && loginPassword == u.getAccountPassword()){
                        acc.setUserAccount(u);
                        check = true;
                        break;
                    }
                }
                if(check == false){cout << "\nLogin failed!";}
                else{
                    int n1;
                    do{
                        UserMenu();
                        cin >> n1;
                        if(n1 == 1){EditPersonalInformation(userList,loginName,loginPassword);}
                        else if(n1 == 2){
                            int n2;
                            do{
                                TourInformationService();
                                cin >> n2;
                                if(n2 == 1){
                                    int n3;
                                    do{
                                        AvaiableService();
                                        cin >> n3;
                                        if(n3 == 1){
                                            ViewTourInformation(tripList);
                                            cout << "\n\n\tDo you want to arrange tour? (y/n) ";
                                            char x; cin >> x;
                                            if(x == 'y'){arrangeTrip(tripList);}
                                        }
                                        else if(n3 == 2){
                                            SearchTransportByLocation(transportList);
                                        }
                                        else if(n3 == 3){
                                            SearchRoomByLocation(hotelList);
                                        }
                                    }
                                    while(n3 != 0);                                   
                                }
                                else if(n2 == 2){
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
                                    int n3; 
                                    do{
                                        BookTourMenu();
                                        cin >> n3;
                                        if(n3 == 1){AddTourInformation(tour,tripList,hotelList,transportList,hotelLogin,transportLogin);}
                                        else if(n3 == 2){ViewTourInformation(tour);}
                                        else if(n3 == 3){EditTourInformation(hotelList,transportList,tour,hotelLogin,transportLogin);}
                                        else if(n3 == 4){DeleteElementInVector<Trip>(tour,"TOUR");}
                                    }
                                    while(n3!=0);
                                    acc.setTourOfCLient(tour);
                                    accountList.push_back(acc);
                                    SaveAccountToTextFile("Data//account.txt",accountList);
                                }
                            }
                            while(n2 != 0);                           
                        }
                    }
                    while(n1 != 0);
                }
            }
        }
        else if(n == 2){SignUp(userList);}
    }
    while (n != 0);

    return 0;
}





