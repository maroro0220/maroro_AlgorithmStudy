
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long n;
		scanf(" %lld", &n);
		long long f, b;
		f = 1 + (2 + (2 + 4 * (n - 2))) * (n - 1) / 2;
		b = 1 + (6 + (6 + 4 * (n - 2))) * (n - 1) / 2;
		printf("#%d %lld %lld\n", test_case, f, b);
		/*
		//dp fail
		vector<vector<long long>> dp(n, vector<long long>(2, 0));
		if (n == 1) {
			printf("#%d %d %d\n", test_case, 1, 1);
			continue;
		}
		else {
			dp[0][0] = 1; dp[0][1] = 1;
			for (long long i = 1; i < n; i++) {
				dp[i][0] = dp[i - 1][0] + 2 + 4 * (i-1);
				dp[i][1] = dp[i - 1][1] + 6 + 4 * (i-1);
			}
			printf("#%d %lld %lld\n", test_case, dp[n-1][0], dp[n-1][1]);

		}
		*/
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}