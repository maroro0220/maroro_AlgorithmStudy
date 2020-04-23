#include <iostream>
#include <cmath>
using namespace std;
long long* arr;
int isPrime(long long n) {
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return 1;
}
int main() {
	long long n;
	scanf("%lld", &n);
	if (n == 1) {
		printf("0");
		return 0;
	}
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (isPrime(i) && isPrime(n / i)) {
				printf("1");
				return 0;
			}
			else {
				printf("0");
				return 0;
			}
		}
	}
	printf("1");
	return 0;
}