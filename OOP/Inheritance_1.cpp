#include<iostream>
#include<string>

using namespace std;

class People {
	protected:
		string name, address;
		int age;
	public:
		People();
		~People();
		void set();
		void get();
};

People::People() {
	name = address = "";
	age = 0;
}
People::~People() {
	name = address = "";
	age = 0;
}
void People::set() {
	cout << "Nhap ten: ";
	//fflush(stdin);
	getline(cin, name);
	cout << "Nhap dia chi: ";
	//fflush(stdin);
	getline(cin, address);
	cout << "Nhap tuoi: ";
	cin >> age;
}
void People::get() {
	cout << "\tThong tin:" << endl;
	cout << "Ho ten: " << name << endl;
	cout << "Dia chi: " << address << endl;
	cout << "Tuoi: " << age << endl;
}

class Students :public People {
	private:
		string id;
		float math, physical, chemistry;
	public:
		Students();
		~Students();
		void set();
		void get();
		float GPA();
};

Students::Students() {
	id = "";
	math = physical = chemistry = 0;
}
Students::~Students() {
	id = "";
	math = physical = chemistry = 0;
}
void Students::set() {
	People::set();
	//fflush(stdin);
	cin.ignore();
	cout << "Nhap ID: ";
	//fflush(stdin);
	getline(cin, id);
	//cin >> id;
	cout << "Nhap diem Toan - Ly - Hoa: ";
	cin >> math >> physical >> chemistry;
}
void Students::get() {
	People::get();
	cout << "ID: " << id << endl;
	cout << "Diem Toan: " << math << endl;
	cout << "Diem Ly: " << physical << endl;
	cout << "Diem hoa: " << chemistry << endl;
	cout << "Diem trung binh: " << GPA() << endl;
}
float Students::GPA() {
	return (math + physical + chemistry) / 3;
}
int main() {
	Students x;
	x.set();
	x.get();
}