#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (auto& el : a)
        scanf("%d", &el);

    sort(a.begin(), a.end());

    printf("%lli", std::max(
        1LL * a[n - 1] * a[n - 2] * a[n - 3], 
        1LL * a[0] * a[1] * a[n - 1]));
}