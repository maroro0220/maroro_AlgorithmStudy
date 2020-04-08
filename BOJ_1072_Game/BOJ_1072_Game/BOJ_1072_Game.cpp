#include<iostream>

using namespace std;

int main() {
	long long X, Y;
	scanf("%lld %lld", &X, &Y);
	int Z = (Y * 100) / X;
	if (Z >= 99) {
		printf("%d", -1);
		return 0;
	}
	int left = 0, right = 1000000000;
	long long mid;
	long long tmp;
	int res = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		tmp = ((Y + mid) * 100) / (X + mid);
		if (tmp <= Z) {
			res = mid + 1;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d", res);
	return 0;
}
