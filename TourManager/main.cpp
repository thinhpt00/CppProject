

#include<iostream>
#include<fstream>
#include <sstream>
#include<map>

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
    map<string,string> saveDataToText;
    std::ifstream inputFile("signUpData.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        // Tách dữ liệu trên mỗi dòng thành các phần tử riêng biệt
        std::istringstream iss(line);
        string user;
        string pass;
        if (iss >> user >> pass) {
            // Lưu các phần tử vào map
            saveDataToText[user] = pass;
        }
    }
    for(auto x : saveDataToText){
        cout << x.first << " - " << x.second << endl;  
    }
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
                    cout << "\nHello, User!\nWhat do you want?";
                    cout << "\n1: addTransport";
                    cout << "\n2: addHotel";
                    cout << "\n3: editPersonalInformation";
                    cout << "\n4: viewTripInformation";
                    cout << "\n5: editTripInformation";
                    cout << "\n6: cancelTripHandles";

                    cout << "\n\nEnter number in range 1 - 8: ";
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

// Back-up data to text file
    std::ofstream outFile("signUpData.txt");
    if (outFile.is_open())
    {
        for(auto x : saveDataToText){
        //string s = x.first + " - " + x.second;
        outFile << x.first << " " << x.second << endl;
        cout << x.first << " - " << x.second << endl;  
    }
        outFile.close();
    }
/////////////
    return 0;
}
