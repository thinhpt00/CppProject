#include<iostream>
using namespace std;

void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 10;
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
int main() {

	int a[100] , n = 10;
	nhap(a, n);
	xuat(a, n);

	xoa(a, n);
	cout << endl;
	xuat(a, n);

	//char a[8] = { 1,2,3,4,5,6,7,8 };
	//char* p = a;
	////cout << a[0];

	//int* ip = (int*)p;
	//cout << "value of *ip: " << ip << endl; // 0x04030201
	//cout << "value of *(ip + 1): " << *(ip + 1) << endl; // 0x08070605

	//int x;
	//cout << &x;

}