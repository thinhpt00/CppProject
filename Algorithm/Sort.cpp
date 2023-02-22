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

void BubbleSort (int a[],int n) {
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
	int a[100];
	int n; cin >> n;
	Input(a, n);
	Output(a, n);
	BubbleSort(a, n);
	cout << endl;
	Output(a, n);
}