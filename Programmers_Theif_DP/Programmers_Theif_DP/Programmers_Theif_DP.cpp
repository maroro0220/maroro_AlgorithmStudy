#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int>>dp;
int solution(vector<int> money) {
	int answer = 0;
	dp = vector<vector<int>>(2, vector<int>(money.size(), 0)); //row 0 is select first house, 1 is select second house
	dp[0][0] = dp[0][1]=money[0];
	dp[1][0] = 0;
	dp[1][1] = money[1];
	for (int i = 0; i < 2; i++) {
		for (int j = 2; j < money.size(); j++) {
			if (i == 0 && j == money.size() - 1) {
				dp[i][j] = dp[i][j - 1]; break;
			}
			dp[i][j] = max(dp[i][j-2] + money[j], dp[i][j - 1]);
		}
	}
	for (int i = 0; i < 2; i++) {
		if (answer < dp[i][money.size() - 1]) answer = dp[i][money.size() - 1];
	}
	return answer;
}
int main() {
	printf("%d\n", solution({1,2,3,1 }));//4
	return 0;
}