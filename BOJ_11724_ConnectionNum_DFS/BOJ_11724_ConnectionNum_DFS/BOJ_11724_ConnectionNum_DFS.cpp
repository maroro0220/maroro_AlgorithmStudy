#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> grap;
vector<int>chk;
int cnt;
void dfs(int cnt) {
	
		chk[cnt] = 1;
		for (int i = 0; i < grap[cnt].size(); i++) {
		if (!chk[grap[cnt][i]]) {	
			chk[grap[cnt][i]] = 1;
			dfs(grap[cnt][i]);
			}
		}
		
	
}
int main() {
	int N, M;
	int no1, no2;
	cin >> N >> M;
	grap = vector < vector<int>>(N + 1);
	chk = vector<int>(N + 1, 0);
	for (int i = 0; i < M; i++) {
		cin >> no1 >> no2;
		grap[no1].push_back(no2);
		grap[no2].push_back(no1);
	}
	for (int i = 1; i <= N; i++)
		sort(grap[i].begin(), grap[i].end());
	for (int i = 1; i <=N; i++) {
		if(!chk[i]){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}