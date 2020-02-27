#include<iostream>
#include<vector>
using namespace std;
vector<long long>dp;
int main() {
	int n;
	cin >> n;
	dp = vector<long long>(n+1);
	dp[0] = 0; dp[1] = 1;

	for (int i = 2; i <dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld", dp[n]);
	return 0;
}