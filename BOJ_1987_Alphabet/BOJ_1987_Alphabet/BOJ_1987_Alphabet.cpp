#include<iostream>
#include<vector>
using namespace std;
//vector<vector<int>> map;
vector<string>map;
vector<vector<int>>chkmap;
vector<int>chk;
int m;
int r, c;
int dx[4] = {0,0,-1,1};
int dy[4] = { -1,1,0,0 };
void dfs(int y,int x, int cnt) {
		if (m < cnt ) m = cnt;
		for(int t=0;t<4;t++){
			int next_y = y + dy[t], next_x = x + dx[t];
				if (next_y < 0 || next_y >= r || next_x < 0 || next_x >= c||chkmap[next_y][next_x]|| chk[map[next_y][next_x] - 'A']) continue;
			chk[ map[next_y][next_x] - 'A'] = 1;
			dfs(next_y,next_x, cnt + 1);
			chk[ map[next_y][next_x] - 'A'] = 0;
		}
}
int main() {
	cin >> r >> c;
	chk = vector<int>(26);
	map = vector<string>(r);
	chkmap = vector<vector<int>>(r,vector<int>(c,0));
	for (int a = 0; a < r; a++) {
		cin >> map[a];
	}
	chk[map[0][0]-'A'] = 1;
	dfs(0, 0, 1);
	cout << m;
	return 0;
}