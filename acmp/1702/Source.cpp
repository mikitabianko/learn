#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	for (int i = n; i > 0; --i) {
		int ind = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[ind] < arr[j]) {
				ind = j;
			}
		}
		arr[ind] ^= arr[i - 1];
		arr[i - 1] ^= arr[ind];
		arr[ind] ^= arr[i - 1];
		
		printf("%d ", ind);
	}

	free(arr);

	return 0;
}