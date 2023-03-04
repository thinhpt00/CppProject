#include<iostream>
using namespace std;

class VeMayBay {
public:
	string tenChuyen;
	int giaVe,ngayBay;
	VeMayBay();
	~VeMayBay();
	void Nhap();
	void Xuat();
	int getGiaVe();

};

VeMayBay::VeMayBay() {
	tenChuyen = "";
	giaVe = ngayBay = 0;
}
VeMayBay::~VeMayBay() {
	tenChuyen = "";
	giaVe = ngayBay = 0;
}
void VeMayBay::Nhap() {
	cout << "Nhap ten chuyen bay: ";
	cin >> this->tenChuyen;
	cout << "Nhap ngay bay: ";
	cin >> this->ngayBay;
	cout << "Nhap gia ve: ";
	cin >> this->giaVe;
}
void VeMayBay::Xuat() {
	cout << "Ten chuyen bay: " << this->tenChuyen << endl;
	cout << "Ngay bay: " << this->ngayBay << endl;
	cout << "Gia ve: " << this->giaVe << endl;
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
	cout << "Nhap gioi tinh: ";
	cin >> gioiTinh;
	cout << "Nhap tuoi: ";
	cin >> tuoi;
}
void Nguoi::Xuat() {
	cout << "Ten: " << hoTen << endl;
	cout << "Gioi tinh: " << gioiTinh << endl;
	cout << "Tuoi: " << tuoi << endl;

}

class HanhKhach:public Nguoi {
public:
	VeMayBay ve[1000];
	int soLuong,tongtien;
	HanhKhach();
	~HanhKhach();
	void Nhap();
	void Xuat();
	int tongTien();
};

HanhKhach::HanhKhach() {
	ve[soLuong];
	soLuong = tongtien = 0;
}
HanhKhach::~HanhKhach() {
	delete []ve;
	soLuong = tongtien = 0;
}
void HanhKhach::Nhap() {
	Nguoi::Nhap();
	cout << "Nhap so luong ve hanh khach da mua: ";
	cin >> soLuong;
	//ve[soLuong];
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


int main() {
	int n;
	cout << "NHAP SO LUONG KHACH HANG: ";
	cin >> n;

	HanhKhach *x = new HanhKhach[n];
	for (int i = 0; i < n; i++) {
		cout << "\n   NHAP THONG TIN NGUOI " << i + 1 << endl;
		x[i].Nhap();
	}	
	for (int i = 0; i < n; i++) {
		x[i].Xuat();
	}
	system("pause");
}