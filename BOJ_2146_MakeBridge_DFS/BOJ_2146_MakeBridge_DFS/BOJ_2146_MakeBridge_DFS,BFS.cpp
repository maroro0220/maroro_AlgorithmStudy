#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
struct Bound
{
	int r, c, ch;
};
vector<vector<int>> map,mapchk;
vector<Bound>bound;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int mini = 200;
void dfs(int r,int c, int ch){
	map[r][c] = ch;
	for (int i = 0; i < 4; i++) {
		int next_r = r + dr[i], next_c = c + dc[i];
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N || map[next_r][next_c]!=1) continue;
		dfs(next_r,next_c,ch);
	}
	Bound tmp;
	tmp.r = r; tmp.c = c; tmp.ch = ch;
	bound.push_back(tmp);
	//cout << ch << endl;
	//cout << r << ' '<<c<<endl;
}
void bfs(Bound b) {

	queue<pair<int, int>> q;
	q.push({ b.r,b.c });
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int a = 0; a < size; a++) {
			pair<int, int> tmp = q.front(); q.pop();
			//cnt = 0;
			int cur_r = tmp.first, cur_c = tmp.second;
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i], next_c = cur_c + dc[i];
				if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= N || map[next_r][next_c] == b.ch || mapchk[next_r][next_c] == 1) continue;
				if (cnt > mini)break;
				if (map[next_r][next_c]) {
					mini = min(mini, cnt);
					return;
				}
				
				//map[next_r][next_c] = -1;
				mapchk[next_r][next_c] = 1;
				q.push({ next_r,next_c });
			}
		}
		cnt++;
	}
}
int main() {
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N));
	
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> map[a][b];
		}
	}
	int ch = 1;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (map[a][b] == 1) {
				dfs(a, b, ++ch);
			}
		}
	}
	for (int i = 0; i < bound.size(); i++) {

		mapchk= vector<vector<int>>(N, vector<int>(N));
		bfs(bound[i]);
	}
	cout << mini;

}