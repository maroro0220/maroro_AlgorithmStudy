#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> trav;
int kk;
int dfs(int cnt, int time_sum,int money_sum) {
	if (time_sum > kk) return -1;
	if (cnt == trav.size()&&time_sum<=kk) {
		return money_sum;
	}
	if (dp[cnt][time_sum]) {
		return dp[cnt][time_sum];
	}
	if (dp[cnt][time_sum]==-1) {
		//return -1;
	}
	int res = -1;
	res = max(res, dfs(cnt + 1, time_sum + trav[cnt][0], money_sum + trav[cnt][1]));
	res = max(res, dfs(cnt + 1, time_sum + trav[cnt][2], money_sum + trav[cnt][3]));
	if (res) {
		dp[cnt][time_sum] = res;
	}
	else if (res==-1) {
		dp[cnt][time_sum] = 0;
	}
	return res;
}
int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	dp = vector<vector<int>>(travel.size(), vector<int>(K+1, 0));
	kk = K;
	trav = travel;
	dp[0][travel[0][0]] = travel[0][1];
	dp[0][travel[0][2]] = travel[0][3];
	answer = dfs(1, travel[0][0], travel[0][1]);
	answer = max(answer, dfs(1, travel[0][2], travel[0][3]));

	return answer;
}

/*
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
}*/
int main() {
	//660
	printf("%d\n", solution(1650, { {500,200,200,100},{800, 370, 300, 120},{700, 250, 300, 90 } }));
	//5900
	printf("%d\n", solution(3000, { {1000, 2000, 300, 700},{1100, 1900, 400, 900},{900, 1800, 400, 700 }, { 1200, 2300, 500, 1200 }}));
	return 0;
}