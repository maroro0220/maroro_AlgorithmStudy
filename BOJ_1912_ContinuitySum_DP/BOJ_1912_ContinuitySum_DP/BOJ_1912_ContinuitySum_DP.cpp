#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int>dp(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	int maxi = dp[0];

	for (int i = 1; i < n; i++) {
		if ((arr[i]+dp[i-1]) >0 ) {
			//dp[i] = max(arr[i] + dp[i - 1],dp[i-1]);
			//if (arr[i] + dp[i - 1] < dp[i - 1])
				//dp[i] = dp[i-1];
		//	else
				//dp[i] = arr[i] + dp[i - 1];
				dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		}
		else {
			dp[i] =max(arr[i],dp[i-1]+arr[i]);
		}
		maxi = max(maxi, dp[i]);
	}
	//maxi = max(maxi, dp[n-1]);
	cout << maxi;

	return 0;
}