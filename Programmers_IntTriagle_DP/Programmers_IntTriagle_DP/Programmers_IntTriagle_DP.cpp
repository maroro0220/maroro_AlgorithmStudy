#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>>tmp(triangle.size(),vector<int>(triangle.size()));
	tmp[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0) {
				tmp[i][j] = tmp[i - 1][0] + triangle[i][0];
			}
			else if (j == i) {
				tmp[i][j] = tmp[i - 1][j - 1] + triangle[i][j];
			}
			else {//1<=j<=i-1
				tmp[i][j] = (tmp[i - 1][j - 1] > tmp[i - 1][j] ? tmp[i - 1][j - 1] : tmp[i - 1][j]) + triangle[i][j];
			}
		}
	}
	int max = 0;
	for (int i = 0; i < triangle.size(); i++) {
		if (max < tmp[triangle.size() - 1][i]) max = tmp[triangle.size() - 1][i];
	}
	answer = max;
	return answer;
}
int main() {
	printf("%d\n", solution({ {7} ,{3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 }}));
	return 0;
}