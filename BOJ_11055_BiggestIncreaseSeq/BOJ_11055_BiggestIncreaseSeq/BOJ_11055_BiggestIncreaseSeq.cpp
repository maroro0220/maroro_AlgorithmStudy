#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>arr(N);
	vector<int>dp(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int maxi=0;
	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j <i; j++) {
			if (arr[i] > arr[j] ) {
				dp[i]= max(dp[j]+arr[i],dp[i]);
				//if (maxi < dp[i]) maxi = dp[i];
				//dp[i] = maxi;
			}
		}
		maxi = max(maxi, dp[i]);
	}
	cout << maxi;
	return 0;
}