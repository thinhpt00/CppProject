#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string myText;
	string x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
	vector<string> lines;
	ifstream MyReadFile("text.txt");
	//while (getline(MyReadFile, myText, ',')) {
	//	// Output the text from the file
	//	cout << myText << "\n";
	//	lines.push_back(myText);
	//}
	while (MyReadFile >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9>>x10>>x11>>x12) {
		cout << x1;
	}

	// Close the file
	MyReadFile.close();

}