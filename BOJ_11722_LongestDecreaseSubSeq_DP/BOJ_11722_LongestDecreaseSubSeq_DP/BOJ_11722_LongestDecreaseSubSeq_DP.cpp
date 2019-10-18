#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N),dp(N,1);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int maxi = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[j] + 1,dp[i]);
			}
			maxi = max(dp[i], maxi);
		}
	}
	cout << maxi;
	return 0;
}