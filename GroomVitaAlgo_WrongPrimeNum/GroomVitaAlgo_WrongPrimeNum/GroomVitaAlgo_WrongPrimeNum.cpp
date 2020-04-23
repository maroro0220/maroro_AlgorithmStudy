#include <iostream>
#include <cmath>
using namespace std;
long long* arr;
int main() {
	long long n;
	scanf("%lld", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	arr = new long long[n + 1]();
	//memset(arr, 1, n + 1);
	int cnt = 0;
	for (long long i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			for (long long j = i * 2; j < n + 1; j += i) {
				arr[j] = 1;
			}
			if ((n % i) == 0) {
				cnt++;
				if (cnt > 2) {
					break;
				}
			}
		}
	}
	if (cnt == 2) {
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}