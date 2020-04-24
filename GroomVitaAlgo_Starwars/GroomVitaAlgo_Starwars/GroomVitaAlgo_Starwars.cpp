#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = new int[n]();
	int* dp = new int[k+1];
	fill(dp, dp + k+1, 10001);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] <= 10000) {
			dp[arr[i]] = 1;
		}
	}
	sort(arr, arr + n);
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n && arr[j]<=i; j++) {
			dp[i] = min(dp[i], dp[i - arr[j]]+1);
		}
	}
	printf("%d", dp[k] == 10001 ? -1 : dp[k]);
	return 0;
}