#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main() {
    // Khai báo kiểu dữ liệu cho các giá trị trong map
    typedef std::string username;
    typedef std::string password;

    // Khai báo và khởi tạo map
    std::map<username, password> accountMap;

    // Mở file và đọc dữ liệu từng dòng một
    std::ifstream inputFile("account.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        // Tách dữ liệu trên mỗi dòng thành các phần tử riêng biệt
        std::istringstream iss(line);
        username user;
        password pass;
        if (iss >> user >> pass) {
            // Lưu các phần tử vào map
            accountMap[user] = pass;
        }
    }

    // In ra dữ liệu trong map
    for (auto& account : accountMap) {
        std::cout << "Username: " << account.first << ", Password: " << account.second << std::endl;
    }

    return 0;
}
