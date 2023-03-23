#include<iostream>
#include<iomanip> // Thư viện dùng để set độ chính xác cho số chấm động
#include<chrono> // Thư viện để dùng hàm đếm tgian chương trình chạy
#include<random> // Thư viện dùng để sử dụng hàm phát sinh số ngẫu nhiên
#include<cstdlib> // Sử dụng hàm srand() và rand()
#include<ctime> // Sử dụng time() , thời gian thực của chương trình

using namespace std;

//auto start = chrono::steady_clock::now(); // Đếm thời gian chương trình chạy
void random() {
	srand(time(NULL)); // Hàm sinh số ngẫu nhiên dựa vào thời gian thực của chương trình 
	int n = rand() % 100 + 1; // rand() là hàm in ra các số ngẫu nhiên được tạo ra từ hàm srand()
	cout << "\n" << n;
}
void nhap(int a[], int n) {
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> uni(1, 1000); // random số từ 1 -> 1000
	for (int i = 0; i < n; ++i) {
		a[i] = uni(rng);
	}
}
void xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}
void xoa(int a[], int &n) {
	int kt, index;
	while (true) {
		index = -1;
		cout << "\nNhap gia tri muon xoa: "; cin >> kt;
		if (kt == -1) break;
		for (int i = 0; i < n; i++) {
			if (a[i] == kt) {
				index = i;
				n--;
				break;
			}
		}
		while (index == -1) {
			cout << "\nKhong co gia tri " << kt << " . Vui long nhap lai gia tri muon xoa: ";
			cin >> kt;
			if (kt == -1) break;
			for (int i = 0; i < n; i++) {
				if (a[i] == kt) {
					index = i;
					n--;
					break;
				}
			}
		}
		if (kt == -1) break;
		for (int i = index; i < n; i++) {
			a[i] = a[i + 1];
		}
		xuat(a, n);
	}
}
void addressCall(int* p) {
	*p = 200;
}
int main() {

#if 1
	int a{ 10 };
	int* p = &a;
	cout << *p;
	addressCall(p);
	
	if (!p) {
		cout << "\np is null pointer\n";
	}
	else
	{
		cout << "\n" << *p;
	}
#endif
// Constant && Pointer
#if 0
	// Con trỏ HẰNG*********************************
	int a(10);
	const int* p = &a;
	cout << *p;
	a = 20; // Biến a có thể thay đổi giá trị vì nó k phải biến hằng
	//*p = 20; // ERROR: Con trỏ HẰNG không thể thay đổi giá trị biến mà nó trỏ tới
	int b(20);
	p = &b; // OK: Con trỏ HẰNG có thể trỏ tới địa chỉ của một biến khác
	cout << *p;

	// HẰNG con trỏ***********************************
	int a1{ 100 };
	int* const p1 = &a1;
	cout << *p1;
	a1 = 200;
	*p1 = 200; // OK: HẰNG con trỏ có thể thay đổi giá trị biến mà nó trỏ tới
	cout << *p1;
	int b1{ 200 };
	//p1 = &b1; // ERROR: HẰNG con trỏ không thể trỏ tới địa chỉ của một biến khác

	// HẰNG con trỏ HẰNG*******************************
	int a2{ 3000 };
	const int* const p2 = &a2;
	//*p2 = 3; // ERROR: HẰNG con trỏ HẰNG không thể thay đổi giá trị biến mà nó trỏ tới
	int b2{ 546 };
	//p2 = &b2; //ERROR: HẰNG con trỏ HẰNG không thể trỏ tới địa chỉ của một biến khác

#endif
// Hàm phát sinh số ngẫu nhiên (random number)
#if 0
	random_device rd;
	mt19937 rng(rd());
	auto a = rng();
	cout << a;
	uniform_int_distribution<int> uni(1,1000); // random số từ 1 -> 1000
	for (int i = 0; i < 10; ++i) {
		int x = uni(rng);
		cout << x << "\n";
	}


#endif
// Đếm tgian chương trình chạy ms
#if 0

	for (int i = 0; i < 1000; i++) {
		cout << i << "\t";
	}
	// Đếm thời gian chương trình chạy
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "\n" << chrono::duration<double, milli>(diff).count() << " ms" << endl;

#endif
// Kích cỡ con trỏ (8 byte (64-bit) or 4 byte (32-bit) )
#if 0

	char i{ 97 };
	//cout << i;
	char* p = NULL;
	cout << sizeof(p);

#endif
// Độ chính xác của số chấm động
#if 0
	float i = 2.66666666666666666666;// độ chính xác của float là từ 6->9 và thường là 7 số
	double i1 = 2.66666666666666666666;// độ chính xác của float là từ 15->18 và thường là 16 số
	int j(100.0015);
	cout << std::setprecision(20) ; // xét độ chính xác phần thập phân của số thực n số
	cout << i << endl;
	cout << i1;
#endif
// Sử dụng hàm
#if 0
	int a[100] , n = 10;
	nhap(a, n);
	xuat(a, n);
	xoa(a, n);
	cout << endl;
	xuat(a, n);
#endif
// Con trỏ
#if 0
	char a[8] = { 1,2,3,4,5,6,7,8 };
	char* p = a;
	//cout << a[0];

	int* ip = (int*)p;
	cout << "value of *ip: " << ip << endl; // 0x04030201
	cout << "value of *(ip + 1): " << *(ip + 1) << endl; // 0x08070605

	int x;
	cout << &x;
#endif
	return 0;
}