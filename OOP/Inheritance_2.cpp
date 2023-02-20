#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Color {
public:
	string TenMau, MaMau;
	Color();
	Color(string TenMau, string MaMau);
	~Color();
	friend istream& operator >> (istream& in, Color& color);
	friend ostream& operator<<(ostream& out, Color color);
	string getTenMau() {
		return this->TenMau;
	}

};
Color::Color() {
	TenMau = MaMau = "";
}
Color::Color(string TenMau, string MaMau) {
	this->TenMau = TenMau;
	this->MaMau = MaMau;
}
Color::~Color() {
	TenMau = MaMau = "";
}
istream& operator >> (istream& in, Color& color) {
	cout << "Nhap ten mau: ";
	in >> color.TenMau;
	cout << "Nhap ma mau: ";
	in >> color.MaMau;
	return in;
}
ostream& operator<<(ostream& out, Color color) {
	out << "Mau: " << color.TenMau << endl;
	out << "Ma: " << color.MaMau << endl;
	return out;
}

class Point {
public:
	int x, y;
	Point();
	Point(int x, int y);
	~Point();
	friend istream& operator>>(istream& in, Point& point);
	friend ostream& operator<<(ostream& out, Point point);
	bool CheoChinh();
};

Point::Point() {
	x = y = 0;
}
Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}
Point::~Point() {
	x = y = 0;
}
istream& operator>>(istream& in, Point& point) {
	cout << "Nhap hoanh do: x = ";
	in >> point.x;
	cout << "Nhap tung do: y = ";
	in >> point.y;
	return in;
}
ostream& operator<<(ostream& out, Point point) {
	out << "Toa do (x,y) = (" << point.x << "," << point.y << ")";
	return out;
}
bool Point::CheoChinh() {
	if (this->x == this->y)
		return true;
	else
		return false;
}

class Pixel :public Color, public Point {
public:
	Pixel();
	Pixel(string MaMau, string TenMau, int x, int y);
	friend istream& operator>>(istream& in, Pixel& pixel);
	friend ostream& operator<<(ostream& out, Pixel pixel);
	bool KiemTra();
};

Pixel::Pixel() {
	MaMau = TenMau = "";
	x = y = 0;
}
Pixel::Pixel(string MaMau, string TenMau, int x, int y) {
	this->MaMau = MaMau;
	this->TenMau = TenMau;
	this->x = x;
	this->y = y;
}
istream& operator>>(istream& in, Pixel& pixel) {
	cout << "Nhap ten mau: ";
	in >> pixel.TenMau;
	cout << "Nhap ma mau: ";
	in >> pixel.MaMau;
	cout << "Nhap hoanh do: x = ";
	in >> pixel.x;
	cout << "Nhap tung do: y = ";
	in >> pixel.y;
	return in;
}
ostream& operator<<(ostream& out, Pixel pixel) {
	cout << "\n";
	out << "Mau: " << pixel.TenMau << endl;
	out << "Ma: " << pixel.MaMau << endl;
	out << "Toa do (x,y) = (" << pixel.x << "," << pixel.y << ")\n";
	return out;
}
bool Pixel::KiemTra() {
	if (this->CheoChinh() && this->TenMau == "Xanh")
		return true;
	else
		return false;
}
int main() {
	
	int n;
	cout << "Ban muon nhap bao nhieu pixel?  ";
	cin >> n;
	Pixel* x = new Pixel[n]; // == Pixel x[100];
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin Pixel " << i + 1 << ": " << endl;
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		if (x[i].KiemTra())
			cout << x[i];
	}
	return 0;
}