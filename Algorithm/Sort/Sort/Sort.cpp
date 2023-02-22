#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

void Input(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
}

void RandomArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}

void BubbleSort(int a[], int n) {
	bool haveSwaped = false;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				haveSwaped = true;
			}
		}
		if (!haveSwaped) {
			break;
		}
	}
}

int main() {
	cout << "Nhap so luong phan tu cua mang: ";
	int n; cin >> n;
	int a[100];
	//for (int i = 0; i < n; i++) {
	//	a[i] = rand() % 100;
	//}
	//for (int i = 0; i < n; i++) {
	//	cout << a[i] << "\t";
	//}
	//Input(a, n);
	RandomArray(a, n);
	Output(a, n);
	BubbleSort(a, n);
	cout << endl;
	cout << "==>" << endl;
	Output(a, n);
}









