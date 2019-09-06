#include <string>
#include <vector>
#include<queue>

using namespace std;
int nn,cnt;
int visit[200];


void dfs(vector<vector<int>> com, int connect){
	visit[connect] = 1;
	for (int i = 0; i < nn; i++) {
		if (!visit[i]&&com[connect][i] == 1 && connect != i) {
			//com[i][connect] = 0;
			dfs(com, i);
		}//end if
		if ((i == nn - 1) && com[connect][i] == 0) {
		//	return;
		}
	}//end for i < nn


}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	cnt = 0;
	nn = n;
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(computers, i);

		}
	}

	answer = cnt;
	printf("%d\n", cnt);
	return answer;
}

int main() {
	int n = 3;
	vector<vector<int>> arr1({
		vector<int>({1,1,0}),
		vector<int>({1,1,0}),
		vector<int>({0,0,1}),
		});
	vector<vector<int>> arr2({
		vector<int>({1,1,0}),
		vector<int>({1,1,1}),
		vector<int>({0,1,1}),
		});
	solution(n, arr1);
	cnt = 0;
	for (int i = 0; i < 200; i++)
		visit[i] = 0;
	solution(n, arr2);
}