#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>st(N),dp(N);
	for (int i = 0; i < N; i++) {
		cin >> st[i];
		dp[i] = st[i];
	}
	dp[1] = st[0] + st[1];
	dp[2] = max(st[2] + st[1], st[2] + dp[0]);
	for (int i = 3; i < N; i++) {
		dp[i] = max(st[i] + st[i - 1] + dp[i - 3], st[i] + dp[i - 2]);
	}
	cout << dp[N - 1];
	return 0;
}