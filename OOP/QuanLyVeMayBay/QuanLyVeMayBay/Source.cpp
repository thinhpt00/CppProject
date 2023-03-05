#include<iostream>
using namespace std;

class date {
public:
	int day, month, year;
	date() {
		this->day = this->month = this->year = 0;
	}
	~date() {
		this->day = this->month = this->year = 0;
	}
	void input() {
		cout << "\nNgay/thang/nam: ";
		cin >> this->day >> this->month >> this->year;
		while (this->day > 31 || this->day < 1 || this->month < 1 || this->month > 12 || this->year < 2020 || this->year > 2050) {
			if (this->day > 31 || this->day < 1) {
				cout << "Vui long nhap lai ngay: ";
				cin >> this->day;
			}
			if (this->month < 1 || this->month > 12) {
				cout << "Vui long nhap lai thang: ";
				cin >> this->month;
			}
			if (this->year < 2020 || this->year > 2050) {
				cout << "Vui long nhap lai nam: ";
				cin >> this->year;
			}
		}

	}
	void output(){
		cout << "Ngay bay: " << this->day << "/" << this->month << "/" << this->year;
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
	this->tenChuyen = "";
	this->giaVe = 0;
}
VeMayBay::~VeMayBay() {
	this->tenChuyen = "";
	this->giaVe = 0;

}
void VeMayBay::Nhap() {
	cout << "Nhap ten chuyen bay: ";
	cin >> this->tenChuyen;
	cout << "Nhap ngay bay: ";
	ngayBay.input();
	cout << "Nhap gia ve: ";
	cin >> this->giaVe;
}
void VeMayBay::Xuat() {
	cout << "Ten chuyen bay: " << this->tenChuyen << endl;
	ngayBay.output();
	cout << "\nGia ve: " << this->giaVe << endl;
}
int VeMayBay::getGiaVe() {
	return this->giaVe;
}

class Nguoi {
public:
	string hoTen, gioiTinh,diaChi;
	int tuoi,sdt;
	Nguoi();
	~Nguoi();
	void Nhap();
	void Xuat();

};

Nguoi::Nguoi() {
	this->hoTen = this->gioiTinh = this->diaChi = "";
	this->tuoi = this->sdt = 0;
}
Nguoi::~Nguoi() {
	this->hoTen = this->gioiTinh = this->diaChi = "";
	this->tuoi = this->sdt = 0;
}
void Nguoi::Nhap() {
	cout << "Nhap ho ten: ";
	cin >> this->hoTen;
	cout << "Nhap gioi tinh: ";
	cin >> this->gioiTinh;
	cout << "Nhap tuoi: ";
	cin >> this->tuoi;
	cout << "Nhap so dien thoai: ";
	cin >> this->sdt;
	cout << "Nhap dia chi: ";
	cin >> this->diaChi;
}
void Nguoi::Xuat() {
	cout << "Ten: " << this->hoTen << endl;
	cout << "Gioi tinh: " << this->gioiTinh << endl;
	cout << "Tuoi: " << this->tuoi << endl;
	cout << "So dien thoai: " << this->sdt << endl;
	cout << "Dia chi: " << this->diaChi << endl;
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
	ve[this->soLuong];
	this->soLuong = this->tongtien = 0;
}
HanhKhach::~HanhKhach() {
	//delete []ve;
	this->soLuong = this->tongtien = 0;
}
void HanhKhach::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap so luong ve hanh khach da mua: ";
	cin >> this->soLuong;
	ve[this->soLuong];
	for (int i = 0; i < this->soLuong; i++) {
		cout << "\n\tNhap thong tin chuyen bay " << i + 1 << endl;
		ve[i].Nhap();
		tongtien += ve[i].getGiaVe();
	}
}
void HanhKhach::Xuat() {
	cout << "\n***THONG TIN KHACH HANG*** " << endl;
	Nguoi::Xuat();
	cout << "\n--THONG TIN CHUYEN BAY-- " << endl;
	for (int i = 0; i < this->soLuong; i++) {
		ve[i].Xuat();
		cout << endl;
	}
	cout << "  ==>Tong so tien la: " << this->tongtien << endl;
	cout << "------------------------------";
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
	system("cls");
	cout << endl << "\tDANH SACH KHACH HANG" << endl;
	for (int i = 0; i < n; i++) {
		x[i].Xuat();
	}
	cout << "\nBan co muon sap xep danh sach khong? y/n" << endl;
	char check; cin >> check;
	if (check == 'y') {
		system("cls");
		BubbleSort(x, n);
		cout << endl << "\tSAU KHI SAP XEP" << endl;
		for (int i = 0; i < n; i++) {
			x[i].Xuat();
		}
	}
	
	system("pause");
}