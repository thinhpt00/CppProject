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
	for (int i = 0; i < n; i++) {
		haveSwaped = false;
		for (int j = 0; j < n-i-1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				haveSwaped = true;
			}
		}
		if (!haveSwaped) break;
	}
}

void SelectionSort(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void InsertionSort(int a[], int n) {
	int key,j;
	for (int i = 0; i < n; i++) {
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] < key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

// Thoat toan sap xep QuickSort
int Partition(int a[], int low, int high) {
	int left, right, pivot;
	left = low;
	right = high - 1;
	pivot = a[high];

	while (true) {
		while (right >= left && a[left] <= pivot) left++;
		while (right >= left && a[right] >= pivot) right--;
		if (right <= left) break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}
void QuickSort(int a[], int low, int high) {
	if (low < high) {
		int pi = Partition(a,low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
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
	//InsertionSort(a, n);
	QuickSort(a, 0, n - 1);
	cout << endl;
	cout << "==>" << endl;
	Output(a, n);
}









