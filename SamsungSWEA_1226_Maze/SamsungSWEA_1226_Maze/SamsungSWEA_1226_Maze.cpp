
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<char>>map(16, vector<char>(16));
vector<vector<int>>chk;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
pair<int, int> fin;
int answer;
int dfs(int r,int c) {
	if (map[r][c] == '3') {
		answer = 1;
		return answer;
		//return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr>15 || nc < 0 || nc>15) continue;
		if (map[nr][nc] != '1' && !chk[nr][nc]) { 
			chk[nr][nc] = 1;
			dfs(nr, nc); 
			//chk[nr][nc] = 0;
		}
	}
	return answer;
}
int bfs(int r,int c) {
	queue<pair<int, int>>q;
	q.push({ r,c });
	while (!q.empty()) {
		int s = q.size();
		for (int j = 0; j < s; j++) {
			int nr = q.front().first;
			int nc = q.front().second;
			q.pop();
			if (map[nr][nc] == '3') return 1;

			for (int i = 0; i < 4; i++) {
				int nxr = nr + dr[i];
				int nxc = nc + dc[i];
				if (nxr < 0 || nxr>15 || nxc < 0 || nxc>15) continue;
				if (map[nxr][nxc] != '1' && !chk[nxr][nxc]) {
					chk[nxr][nxc] = 1;
					q.push({ nxr,nxc });
				}
			}
		}

	}

	return answer;
	
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case;
		pair<int, int>start;
		chk= vector<vector<int>>(16, vector<int>(16, 0));
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				cin >> map[i][j];
				if (map[i][j] == '2') start = { i,j };
				
			}
		}
		answer = 0; 
		//cout << '#' << test_case << ' ' << dfs(start.first,start.second) << endl;
		cout << '#' << test_case << ' ' << bfs(start.first, start.second) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}