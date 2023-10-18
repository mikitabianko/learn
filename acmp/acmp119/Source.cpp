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
	int n, h, m, s;
	scanf("%d", &n);

	int* times = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &h, &m, &s);
		times[i] = h * 3600 + m * 60 + s;
	}

	sort(times, times + n);

	for (int i = 0; i < n; ++i) {
		h = times[i] / 3600;
		m = times[i] / 60 % 60;
		s = times[i] % 60;
		printf("%d %d %d\n", h, m, s);
	}
	free(times);
	return 0;
}