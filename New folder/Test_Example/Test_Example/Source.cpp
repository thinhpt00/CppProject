#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main() {
	//float toan = 6.25;
	//float ly = 8.75;
	//float hoa = 10;
	//string x = "Pham The Thinh";
	//string y = "Viet Hung - Dong Anh - Ha Noi";
	//string sbd = "MH370369";

	//cout << setw(20) << left << "Ho ten" << setw(35) << left << "Que quan" << setw(15) << left << "So bao danh" << setw(10) << left << "Toan" << setw(10) << left << "Ly" << setw(10) << left << "Hoa";
	//cout << "\n" << setw(20) << left << x << setw(35) << left << y << setw(15) << left << sbd
	//	<< setw(10) << left << toan << setw(10) << left << ly << setw(10) << left << hoa;
	
	//cout << s.size();

	//string s1;
	//s1 = "-> " + s.substr(0, 1) + " la type Triangle, (" + s.substr(2, 1) + "," + s.substr(4, 1)
	//	+ ") (" + s.substr(6, 1) + "," + s.substr(8, 1) + ") (" + s.substr(10, 1) + "," + s.substr(12, 1)
	//	+ ") la 3 dinh cua tam giac";
	//cout << s1;
	//cout << s[2];
	//cout << "\n" << s1;
	string s = "0 1 2 3 444 5 6";
	stringstream ss(s);
	string x, y, x1, y1, x2, y2;
	string type;
	ss >> type;
	cout << type;
	ss >> type >> x >> y >> x1 >> y1 >> x2 >> y2;
	cout << x << "\n";
	cout << y << "\n";


	

	//stringstream ss(s);

	//string s1;

	//while (ss >> s1) {
	//	cout << s1 << "\n";
	//}


}