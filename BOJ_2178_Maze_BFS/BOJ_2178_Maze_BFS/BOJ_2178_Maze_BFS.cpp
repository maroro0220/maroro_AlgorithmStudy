#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<pair<int,int>>q;
vector<vector<int>>map;
//vector<string>map;
int mini,N,M;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
vector<vector<int>>chk;
void bfs() {
	q.push({ 0,0 });
	int cnt = 0;
	while (!q.empty()) {
		//int s = q.size();
		//for (int a = 0; a < s; a++) {
			pair<int, int> cur = q.front(); q.pop();
			
			for (int i = 0; i < 4; i++) {
				int cur_r = cur.first + dr[i], cur_c = cur.second + dc[i];
				if (cur_r == N - 1 && cur_c == M - 1) {
					cout << chk[cur.first][cur.second] + 1;
					return;
				}
				if (cur_r < 0 || cur_r >= N || cur_c < 0 || cur_c >= M ||chk[cur_r][cur_c]) continue;
				//if (chk[cur_r][cur_c] || !map[cur_r][cur_c]) continue;
				if (!map[cur_r][cur_c]) continue;

				chk[cur_r][cur_c] = chk[cur.first][cur.second] + 1;
				q.push({ cur_r,cur_c });
			}
		//}
		//cnt++;
	}
	return;
	//cout << cnt;
}
int main() {
	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M));
	//map = vector<string>(N);
	chk = vector<vector<int>>(N, vector<int>(M,0));
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			//cin >> map[a];
			scanf("%1d", &map[a][b]);
		}
	}
	chk[0][0] = 1;
	bfs();
	return 0;
}