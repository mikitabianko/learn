#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sort(int* begin, int* end) {
	for (; end != begin; --end) {
		for (int* i = begin; i != end - 1; ++i) {
			if (*i > *(i + 1)) {
				*i ^= *(i + 1);
				*(i + 1) ^= *i;
				*i ^= *(i + 1);
			}
		}
	}
}

int main() {
	int n, count = 0;
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n / 2 + 1; ++i) {
		count += arr[i] / 2 + 1;
	}

	printf("%d", count);

	free(arr);
	return 0;
}