#include <string>
#include <vector>
#include<algorithm>
using namespace std;
/*
int dfs(vector<vector<int>> trav,vector<int> dp, int cnt, int time_sum, int kk) {
	if (cnt == trav.size()) {
		return 0;
	}
	for (int i = 0; i < 4; i += 2) {
		if (time_sum + trav[cnt][i] > kk) {
			continue;
		}
		dp[cnt] = max(dp[cnt], dp[cnt - 1] + trav[cnt][i + 1]);
		dp[cnt] = dfs(trav, dp , cnt + 1, time_sum + trav[cnt][i],kk);
	}
	return dp[cnt-1];
}
*/
int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	vector<vector<int>> dp(travel.size(),vector<int>(K+1,0));
	dp[0][travel[0][0]] = travel[0][1];//first city [0][0]=walk time [0][1]=walk money
	dp[0][travel[0][2]] = travel[0][3];//first city [0][2]=bike time [0][3]=bike money
	for (int i = 1; i < travel.size(); i++) {
		for (int j = 1; j <= K; j++) {
			if (dp[i - 1][j] == 0) continue;
			if (K >= j + travel[i][0]) {
				dp[i][j + travel[i][0]] = max(dp[i][j + travel[i][0]], dp[i - 1][j] + travel[i][1]);
				answer = max(dp[i][j + travel[i][0]], answer);
			}
			if (K >= j + travel[i][2]) {
				dp[i][j + travel[i][2]] = max(dp[i][j + travel[i][2]], dp[i - 1][j] + travel[i][3]);
				answer = max(dp[i][j + travel[i][2]], answer);
			}
		}
	}
	return answer;
}
int main() {

	printf("%d\n", solution(1650, { {500,200,200,100},{800, 370, 300, 120},{700, 250, 300, 90 } }));
	printf("%d\n", solution(3000, { {1000, 2000, 300, 700},{1100, 1900, 400, 900},{900, 1800, 400, 700 }, { 1200, 2300, 500, 1200 }}));
	return 0;
}