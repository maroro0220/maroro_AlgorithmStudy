#include<vector>
#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp(N+1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <=N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}
	cout << dp[N] << endl;
	return 0;
}