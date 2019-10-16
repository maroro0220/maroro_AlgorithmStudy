#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n,T;
	cin >> T;
	while (T--) {
		cin >> n;
		int maxi = 0;
		vector<vector<int>>st(2, vector<int>(n, 0));
		vector<vector<int>>dp(2, vector<int>(n, 0));

		for (int a = 0; a < 2; a++) {
			for (int b =0; b <n; b++) {
				cin >> st[a][b];
			}//end for b
		}//end for a
	/*
		int sum_e = 0,sum_o=0;
		for (int a = 0; a < 2; a++) {
			for (int b=0; b < n; b ++) {
				if ((a + b) % 2 == 0) {
					sum_e += st[a][b];
				}
				else if ((a + b) % 2) {
					sum_o += st[a][b];
				}
			}
		}
		maxi = sum_e > sum_o ? sum_e :sum_o;
		*/
		if (n == 1) {
			maxi = st[0][0] > st[1][0] ? st[0][0] : st[1][0];
		}
		/*
		else if (n == 2) {
			maxi = (st[0][0] + st[1][1]) > (st[1][0] + st[0][1]) ? (st[0][0] + st[1][1]) : (st[1][0] + st[0][1]);
			cout << maxi;
		}
		*/
		else {
			dp[0][0] = st[0][0];
			dp[1][0] = st[1][0];
			dp[1][1] = dp[0][0] + st[1][1];
			dp[0][1] = dp[1][0] + st[0][1];
			for (int i = 2; i < n; i++) {
				dp[0][i] = st[0][i]+(dp[1][i - 1] > dp[1][i - 2] ? dp[1][i - 1] : dp[1][i - 2]);
				dp[1][i] = st[1][i]+(dp[0][i - 1] > dp[0][i - 2] ? dp[0][i - 1] : dp[0][i - 2]);
			}//end for
			maxi = dp[0][n - 1] > dp[1][n - 1] ? dp[0][n - 1] : dp[1][n - 1];
		}//end else 
		cout << maxi << endl;
	}//end while
	return 0;
}