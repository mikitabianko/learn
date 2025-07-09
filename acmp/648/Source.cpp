#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int* begin, int* end) {
	for (; end > begin; --end) {
		for (int* j = begin; j < end - 1; ++j) {
			if (*j > *(j + 1)) {
				*j ^= *(j + 1);
				*(j + 1) ^= *j;
				*j ^= *(j + 1);
			}
		}
	}
}

int main() {
	int n, sum = 0;

	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		sum += arr[i];
	}

	sum *= -1;

	sort(arr, arr + n);

	for (int i = n / 2; i < n; ++i) {
		sum += arr[i] * 2;
	}

	printf("%d", sum);

	free(arr);
	return 0;
}