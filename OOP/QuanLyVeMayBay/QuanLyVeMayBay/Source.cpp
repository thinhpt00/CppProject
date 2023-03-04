#include<iostream>
using namespace std;

class date {
public:
	int day, month, year;
	date() {
		day = month = year = 0;
	}
	~date() {
		day = month = year = 0;
	}
	void input() {
		cout << "\nNgay/thang/nam: ";
		cin >> day >> month >> year;
		while (day > 31 || day < 1 || month < 1 || month > 12 || year < 2020 || year > 2050) {
			if (day > 31 || day < 1) {
				cout << "Vui long nhap lai ngay: ";
				cin >> day;
			}
			if (month < 1 || month > 12) {
				cout << "Vui long nhap lai thang: ";
				cin >> month;
			}
			if (year < 2020 || year > 2050) {
				cout << "Vui long nhap lai nam: ";
				cin >> year;
			}
		}

	}
	void output(){
		cout << "Ngay bay: " << day << "/" << month << "/" << year;
	}
};

class VeMayBay {
public:
	string tenChuyen;
	int giaVe;
	date ngayBay;
	VeMayBay();
	~VeMayBay();
	void Nhap();
	void Xuat();
	int getGiaVe();

};

VeMayBay::VeMayBay() {
	tenChuyen = "";
	giaVe = 0;
}
VeMayBay::~VeMayBay() {
	tenChuyen = "";
	giaVe = 0;

}
void VeMayBay::Nhap() {
	//cout << "Nhap ten chuyen bay: ";
	//cin >> this->tenChuyen;
	//cout << "Nhap ngay bay: ";
	//ngayBay.input();
	cout << "Nhap gia ve: ";
	cin >> this->giaVe;
}
void VeMayBay::Xuat() {
	//cout << "Ten chuyen bay: " << this->tenChuyen << endl;
	//ngayBay.output();
	cout << "\nGia ve: " << this->giaVe << endl;
}
int VeMayBay::getGiaVe() {
	return this->giaVe;
}

class Nguoi {
public:
	string hoTen, gioiTinh;
	int tuoi;
	Nguoi();
	~Nguoi();
	void Nhap();
	void Xuat();

};

Nguoi::Nguoi() {
	hoTen = gioiTinh = "";
	tuoi = 0;
}
Nguoi::~Nguoi() {
	hoTen = gioiTinh = "";
	tuoi = 0;
}
void Nguoi::Nhap() {
	cout << "Nhap ho ten: ";
	cin >> hoTen;
	//cout << "Nhap gioi tinh: ";
	//cin >> gioiTinh;
	//cout << "Nhap tuoi: ";
	//cin >> tuoi;
}
void Nguoi::Xuat() {
	cout << "Ten: " << hoTen << endl;
	//cout << "Gioi tinh: " << gioiTinh << endl;
	//cout << "Tuoi: " << tuoi << endl;

}

class HanhKhach:public Nguoi {
public:
	VeMayBay ve[1000];
	int soLuong,tongtien;
	HanhKhach();
	~HanhKhach();
	void Nhap();
	void Xuat();
	bool operator < (const HanhKhach& obj)
	{
		if (this->tongtien < obj.tongtien) return true;
		else return false;
	}
};

HanhKhach::HanhKhach() {
	ve[soLuong];
	soLuong = tongtien = 0;
}
HanhKhach::~HanhKhach() {
	//delete []ve;
	soLuong = tongtien = 0;
}
void HanhKhach::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap so luong ve hanh khach da mua: ";
	cin >> soLuong;
	ve[soLuong];
	for (int i = 0; i < soLuong; i++) {
		cout << "\n\tNhap thong tin chuyen bay " << i + 1 << endl;
		ve[i].Nhap();
		tongtien += ve[i].getGiaVe();
	}
}
void HanhKhach::Xuat() {
	cout << "\n***THONG TIN KHACH HANG*** " << endl;
	Nguoi::Xuat();
	cout << "\n--THONG TIN CHUYEN BAY-- " << endl;
	for (int i = 0; i < soLuong; i++) {
		ve[i].Xuat();
		cout << "--------------------";
		cout << endl;
	}
	cout << "==>Tong so tien la: " << tongtien << endl;
}

void Swap(HanhKhach& a, HanhKhach& b) {
	HanhKhach temp = a;
	a = b;
	b = temp;
}

void BubbleSort(HanhKhach a[], int n) {
	bool temp = false;
	for (int i = 0; i < n-1; i++) {
		temp = false;
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] < a[j + 1]) {
				Swap(a[j], a[j + 1]);
				temp = true;
			}
		}
		if (temp == false) break;
	}
}

int main() {
	int n;
	cout << "NHAP SO LUONG KHACH HANG: ";
	cin >> n;

	HanhKhach *x = new HanhKhach[n];
	for (int i = 0; i < n; i++) {
		cout << "\n   NHAP THONG TIN NGUOI " << i + 1 << endl;
		x[i].Nhap();
	}	
	cout << endl << "\t\nOUTPUT" << endl;
	for (int i = 0; i < n; i++) {
		x[i].Xuat();
	}
	BubbleSort(x,n);
	cout << endl << "\t\nSAU KHI SAP XEP" << endl;
	for (int i = 0; i < n; i++) {
		x[i].Xuat();
	}

	system("pause");
}