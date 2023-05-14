// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <map>

// using namespace std;
// map<string,string> text(const string& fileName){
//     map<string,string> x;
//     ifstream file(fileName);
//     if (file.is_open()) {
//         string data;
//         while(getline(file, data)){
//             stringstream ss(data);
//             vector<string> words;
//             string word;
//             while (getline(ss, word, ';')) {
//                 words.push_back(word);
//             }
//             x[words[0]] = words[1];
//         }
//         file.close();
//     }
//     return x;
// }
// int main() {
//     map<string,vector<int>> xx;

//     // In ra màn hình các chuỗi đã đọc được
//     for (auto w : text("signUpData.txt")) {
//         cout << w.first << " - " << w.second << endl;
//     }

//     return 0;
// }



// #include <iostream>
// #include <map>
// #include <vector>
// using namespace std;
// int main() {
//     vector<int> x = {1,2,3};
//     vector<int> y = {1,3};
//     vector<int> z = {3};
//     map<int, vector<int>> my_map = {{1, x}, {2,y}, {3,z}};
//     my_map[1] = x;
//     my_map[2] = y;
//     my_map[3] = z;
//     // remove the element with key 2
//     my_map.erase(2);

//     // print the remaining elements
//     for (const auto& pair : my_map) {
//         std::cout << "Key: " << pair.first << std::endl;
//         std::cout << "Values: ";
//         for (int x : pair.second) {
//             std::cout << x << " ";
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }




// #include <iostream>
// #include <string>
// #include <algorithm>

// std::string trim(const std::string& str)
// {
//     const auto strBegin = str.find_first_not_of(" \t");
//     if (strBegin == std::string::npos)
//         return "";
//     const auto strEnd = str.find_last_not_of(" \t");
//     const auto strRange = strEnd - strBegin + 1;
//     return str.substr(strBegin, strRange);
// }
// std::string normalize(const std::string& str)
// {
//     std::string result;
//     std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), [](char c) {
//         return !std::isalnum(c);
//     });
//     return result;
// }
// std::string toLower(const std::string& str)
// {
//     std::string result = str;
//     std::transform(str.begin(), str.end(), result.begin(), [](unsigned char c) {
//         return std::tolower(c);
//     });
//     return result;
// }
// std::string normalizeInput(std::string& str)
// {
//     str = trim(str);
//     str = normalize(str);
//     str = toLower(str);
//     return str;
// }

// int main()
// {
//     std::cout << "Enter a string to normalize:" << std::endl;
//     std::string input;
//     std::getline(std::cin, input);
//     //std::string normalized = normalizeInput(input);
//     std::cout << "Normalized string: " << normalizeInput(input) << std::endl;
//     return 0;
// }




#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "C:\Users\Thinh\Documents\Github\TourManager\hppFile\trip.hpp"
#include <fstream>
#include <sstream>
using namespace std;

string NormalizeString(const string& str) {
    std::string result;
    bool inWord = false;
    for (char c : str) {
        if (std::isspace(c)) {
            if (inWord) {
                inWord = false;
                result += ' ';
            }
        } else {
            if (!inWord) {
                inWord = true;
                result += std::toupper(c);
            } else {
                result += std::tolower(c);
            }
        }
    }
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

int main() {
    // std::string input = "  23 - 25 -       2023   ";
    // std::string output = normalizeString(input);
    // std::cout << output << '\n'; // This Is A String With Extra Spaces

    vector<Trip> x;
    ifstream file("tour.txt");
    if (file.is_open()) {
        string data;
        while(getline(file, data)){
            stringstream ss(data);
            vector<string> s;
            string word;
            while (getline(ss, word, ';')) {
                s.push_back(word);
            }
            // cout << s.size() << endl;
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
            // cout << transport.size() << endl;

            vector<Hotel> hotel;
            Hotel hotel_;
            hotel_.setHotelName(NormalizeString(s[6]));
            hotel_.setHotelAddress(NormalizeString(s[7]));
            hotel_.setRoomType(NormalizeString(s[8]));
            hotel_.setStartDay(NormalizeString(s[9]));
            hotel_.setRoomPrice(stof(s[10]));
            hotel.push_back(hotel_);
            // cout << hotel.size() << endl;

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

    return 0;
}
