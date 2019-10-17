#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>wine(n),dp(n);
	for (int a = 0; a < n; a++) {
		cin >> wine[a];
	}
	dp[0] = wine[0];
	dp[1] = wine[1]+dp[0];
	dp[2] = max(wine[0]+wine[2],wine[1]+wine[2] );
	dp[2] = max(dp[1], dp[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n-1];
	return 0;
}