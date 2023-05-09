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



#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    vector<int> x = {1,2,3};
    vector<int> y = {1,3};
    vector<int> z = {3};
    map<int, vector<int>> my_map = {{1, x}, {2,y}, {3,z}};
    my_map[1] = x;
    my_map[2] = y;
    my_map[3] = z;
    // remove the element with key 2
    my_map.erase(2);

    // print the remaining elements
    for (const auto& pair : my_map) {
        std::cout << "Key: " << pair.first << std::endl;
        std::cout << "Values: ";
        for (int x : pair.second) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
