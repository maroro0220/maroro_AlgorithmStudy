#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int>dp;
	int maxi = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	dp=vector<int>(N,0);
	dp[0] = 1;
	for (int k = 0; k < N; k++) {
		int tmp = 0;
		for (int i = 0; i < k; i++) {
			if (a[k] > a[i]) {
				if (tmp < dp[i]) {
					tmp = dp[i];
				}
			}
		}
		dp[k] = tmp + 1;
		maxi = max(maxi, dp[k]);
		/*		
		for (int i = k+1; i < N; i++) {
			if (a[i] > a[i - 1]) dp[i] = dp[i - 1] + 1;
			else { dp[i] = dp[i - 1]; i++; }
		}
		*/
		//maxi = max(maxi, dp[N - 1]);
	}
	cout << maxi;
	return 0;
}