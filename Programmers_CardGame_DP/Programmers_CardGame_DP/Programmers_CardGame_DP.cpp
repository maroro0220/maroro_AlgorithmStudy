#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<vector<int>>dp;
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	dp = vector<vector<int>>(left.size() + 1, vector<int>(right.size() + 1, 0));

	//for (int i = 1; i <= left.size() + 1; i++) {	dp[0][i] = -1;}
	for (int i = 0; i < left.size(); i++) {
		for (int j = 0; j < right.size(); j++) {
			//cout << "i: " << i << "j: " <<j<< endl;
			//cout << "before dp i+1 j+1 => dp[i][j]:" << dp[i][j] << ' ' << endl;
			dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i][j]);
			//cout << "1after dp i+1 j+1: " << dp[i + 1][j + 1] << endl;
			if (left[i] > right[j]) {
				dp[i + 1][j + 1] = dp[i + 1][j] + right[j];
			}
			//cout << "2after dp i+1 j+1: " << dp[i + 1][j + 1] << endl;

		}
		cout << endl;
	}
	for (int i = 0; i < right.size() + 1; i++) {
		if (answer < dp[left.size()][i]) answer = dp[left.size()][i];
	}
	return answer;
}

int main() {

	printf("%d\n", solution({ 3,2,5 }, { 2,4,1 }));//7
	return 0;
}