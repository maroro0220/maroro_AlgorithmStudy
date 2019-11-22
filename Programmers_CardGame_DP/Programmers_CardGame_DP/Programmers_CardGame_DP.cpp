#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<vector<int>>dp;
vector<int> l, r;
int dfs(int lef, int righ) {
	if (lef == l.size() || righ == r.size()) {
		return 0;
	}
	if (dp[lef][righ] != -1) {
		return dp[lef][righ];
	}
	dp[lef][righ] = max(dfs(lef + 1, righ), dfs(lef + 1, righ + 1));
	if (l[lef] > r[righ]) {
		dp[lef][righ] = dfs(lef , righ + 1)+r[righ];
	}
	return dp[lef][righ];
}
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	dp = vector<vector<int>>(left.size() + 1, vector<int>(right.size() + 1, -1));
	l = left;
	r = right;
	/*
	for (int i = 0; i < left.size(); i++) {
		for (int j = 0; j < right.size(); j++) {
			dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]);
			if (left[i] > right[j]) {
				dp[i + 1][j + 1] = dp[i + 1][j] + right[j];
			}

		}
		cout << endl;
	}
	for (int i = 0; i < right.size() + 1; i++) {
		if (answer < dp[left.size()][i]) answer = dp[left.size()][i];
	}
	*/
	answer = dfs(0, 0);
	return answer;
}

int main() {

	printf("%d\n", solution({ 3,2,5 }, { 2,4,1 }));//7
	return 0;
}