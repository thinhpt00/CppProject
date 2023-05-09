#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
map<string,string> text(const string& fileName){
    map<string,string> x;
    ifstream file(fileName);
    if (file.is_open()) {
        string data;
        while(getline(file, data)){
            stringstream ss(data);
            vector<string> words;
            string word;
            while (getline(ss, word, ';')) {
                words.push_back(word);
            }
            x[words[0]] = words[1];
        }
        file.close();
    }
    return x;
}
int main() {
    map<string,vector<int>> xx;

    // In ra màn hình các chuỗi đã đọc được
    for (auto w : text("signUpData.txt")) {
        cout << w.first << " - " << w.second << endl;
    }

    return 0;
}
