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
		haveSwaped = false;
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

void SelectionSort(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void InsertionSort(int a[], int n) {
	int key, j;
	for (int i = 1; i < n ; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

int main() {
	cout << "Nhap so luong phan tu cua mang: ";
	int n; cin >> n;
	int a[100];
	//Input(a, n);
	RandomArray(a, n);
	Output(a, n);
	//BubbleSort(a, n);
	//SelectionSort(a, n);
	InsertionSort(a, n);
	cout << endl;
	cout << "==>" << endl;
	Output(a, n);
}









