#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, count = 0;
	scanf("%d", &n);
	
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
				++count;
			}
		}
	}
	
	printf("%d", count);

	delete[] arr;
  return 0;
}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	int n, count = 0;
//	cin >> n;
//	vector<int> arr(n);
//	for (auto& el : arr) {
//		cin >> el;
//	}
//
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n - i - 1; ++j) {
//			if (arr[j] > arr[j + 1]) {
//				swap(arr[j], arr[j + 1]);
//				++count;
//			}
//		}
//	}
//
//	cout << count;
//
//	return 0;
//}