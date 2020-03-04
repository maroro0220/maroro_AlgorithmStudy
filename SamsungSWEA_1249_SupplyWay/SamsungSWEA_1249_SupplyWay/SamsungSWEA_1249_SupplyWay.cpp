
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> chk_map;
int N;
int mini;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };
/* Time Over
void dfs(int r, int c,int cnt) {
	if (r == N - 1 && c == N - 1) {
		mini = min(mini, cnt);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int next_x, next_y;
		next_x = c + dx[d];
		next_y = r + dy[d];
		if (next_x>=0&&next_x<N&&next_y>=0&&next_y<N&&!chk_map[next_y][next_x]) {
			cnt += map[next_y][next_x];
			chk_map[next_y][next_x] = 1;
			dfs(next_y, next_x,cnt);
			chk_map[next_y][next_x] = 0;			
			cnt -= map[next_y][next_x];
		}
	}
}
*/
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{ 
		cin >> N;
		mini = 10*N;
		map = vector<vector<int>>(N, vector<int>(N));
		chk_map = vector<vector<int>>(N, vector<int>(N,0));
		chk_map[0][0] = 1;
		for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < N; j++) {
				map[i][j] = tmp[j]-'0';
			}
		}
		dfs(0, 0,0);
		cout << '#' << test_case << ' ' << mini<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}