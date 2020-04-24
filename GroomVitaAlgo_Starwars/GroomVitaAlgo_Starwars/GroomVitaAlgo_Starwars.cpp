#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = new int[n]();
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n,greater<int>());
	int cnt = 0;
	bool chk = false;
	for (int i = 0; i < n;) {
		if (k - arr[i] > 0) {
			k -= arr[i];
			cnt++;
		}
		else if (k - arr[i] == 0) {
			chk = true;
		}
		else {
			i++;
		}
	}
	if (!chk) {
		printf("-1");
	}
	else {
		printf("%d", cnt);
	}return 0;
}