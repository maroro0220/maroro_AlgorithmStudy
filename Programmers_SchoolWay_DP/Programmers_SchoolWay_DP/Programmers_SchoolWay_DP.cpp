#include <string>
#include <vector>

using namespace std;

vector<vector<int>>dp;
/*
int mm, nn;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int dfs(int r,int c) {
	if (dp[r][c]) { return dp[r][c]; }
	if (c == mm && r == nn) { 
		return 1; 
	}
	else {
		int next_r, next_c;
		for (int i = 0; i < 4; i++) {
			next_r = r + dr[i];
			next_c = c + dc[i];
			if ( next_r>nn||next_c>mm||next_r<1||next_c<1) {
				continue; 
			}
			if (dp[next_r][next_c] == -1) continue;
			dp[r][c]+=dfs(next_r,next_c);
		}
	}
	return dp[r][c];
}
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	mm = m; nn = n;
	dp = vector<vector<int>>(n+1, vector<int>(m+1,0));
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][0]][puddles[i][1]] = -1;
	}
	dfs(1, 1);
	answer = dp[1][1];
	return answer;
}
*/

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	dp = vector<vector<int>>(n+1, vector<int>(m+1, 0));
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1]][puddles[i][0]] = -1;
	}
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == -1) dp[i][j] = 0;
			else {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	answer = dp[n][m];
	return answer;
}
int main() {
	printf("%d\n", solution(4, 3, { {2,2} }));//4
	return 0;
}