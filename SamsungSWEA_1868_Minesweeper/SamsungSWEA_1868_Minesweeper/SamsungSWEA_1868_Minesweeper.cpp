
#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> map;
vector<vector<int>> chk_arr;
int N;
int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = { -1,0,1,1,1,0,-1,-1 };
int ans;
int Chk(int r, int c) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
		if (map[next_r][next_c] == '*') cnt++;
	}
	return cnt;
}
int dfs(int r,int c,int cnt) {
		int chk_ret = Chk(r, c);
		map[r][c] = chk_ret+'0';
		chk_arr[r][c] = 1;
		if (chk_ret == 0) {
			for (int i = 0; i < 8; i++) {
				int next_r = r + dr[i];
				int next_c = c + dc[i];
				if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
				if (map[next_r][next_c] == '*')continue;
				if (map[next_r][next_c] == '.') {
					int next_ret = Chk(next_r, next_c);
					map[next_r][next_c] = next_ret + '0';
				
					if (next_ret == 0) {
							dfs(next_r, next_c, cnt);
					}
				}
				if (chk_arr[next_r][next_c]&&map[next_r][next_c]!='0') {
						ans--;
						chk_arr[next_r][next_c] = 0;
				}
			}
	}
	return cnt;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		map = vector<vector<char>>(N, vector<char>(N));
		chk_arr = vector<vector<int>>(N, vector<int>(N,0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '.') {
					ans++;
					dfs(i, j,0);
				}
			}
		}
		printf("#%d %d\n",test_case, ans);

		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}