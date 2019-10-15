#include<iostream>
#include<vector>
//#include<cmath>
//#include<string>
using namespace std;

int N;
/*
bool Chk(int n) {
	string tmp = to_string(n);
	for (int i = 0; i < tmp.size()-1; i++) {
		if (abs(tmp[i] - tmp[i + 1]) != 1) return false;
	}
	return true;
}
int main() {
	cin >> N;
	int cnt = 0;
	for (int ind = pow(10, N - 1); ind<pow(10, N); ind++) {
		if (Chk(ind)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
*/
int main() {
	cin >> N;
	vector < vector<int>>dp(N + 1, vector<int>(10, 0));
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int a = 2; a < N + 1; a++) {
		dp[a][0] = dp[a - 1][1];
		for (int b =0; b <= 9; b++) {
			if (b == 0) {
				dp[a][b] = dp[a - 1][b + 1] % 1000000000;
			}
			else if (b == 9) {
				dp[a][b] = dp[a - 1][b - 1] % 1000000000;
			}
			else
				dp[a][b] = (dp[a - 1][b - 1] + dp[a - 1][b + 1])%1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum = (sum+dp[N][i])%1000000000;
	}
	cout << sum ;
}