#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> dp(N+1,1);
	dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1]+dp[i-2];
	}
	cout << dp[N];
	return 0;
}