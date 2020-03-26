
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> map;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int n,ret;
void dfs(int r,int c, int cnt) {
	int next_r, next_c;
	if (ret < cnt)ret = cnt;
	for (int i = 0; i < 4; i++) {
		next_r = r + dr[i];
		next_c = c + dc[i];
		if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n)continue;
		if ((map[r][c] + 1) == map[next_r][next_c]) {
			dfs(next_r, next_c, cnt + 1); 
		}
	}
	//return cnt;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		map = vector<vector<int>>(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin>>map[i][j];
			}
		}
		int maxi = 0;
		int res=1000000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ret = 0;
				dfs(i, j,1);
				if (maxi < ret) { 
					maxi = ret; 
					res = map[i][j];
				}
				else if (maxi == ret) {
					if (res > map[i][j]) res = map[i][j];
				}
			}
		}
		printf("#%d %d %d\n", test_case, res, maxi);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}