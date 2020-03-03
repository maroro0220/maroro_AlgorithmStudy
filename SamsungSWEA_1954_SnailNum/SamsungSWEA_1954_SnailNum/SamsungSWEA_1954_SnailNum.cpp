
#include<iostream>
#include<vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> arr;
void dfs(int r,int c,int cnt) {

}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		int dir = 0;
		int cnt = 1;
		cin >> n;
		arr = vector < vector<int>>(n, vector<int>(n, 0));
		arr[0][0] = cnt;
		int i = 0, j = 0;
		while (1) {
			if ((i + dy[dir]) >= 0 && (j + dx[dir]) >= 0 && (i + dy[dir]) < n && (j + dx[dir]) < n && !arr[i + dy[dir]][j + dx[dir]]) {
					i = i + dy[dir];
					j = j + dx[dir];
					cnt++;
					arr[i][j] = cnt;
			}
			else {
				if (dir == 3) {
					dir = 0;
				}
				else {
					dir++;
				}
			}
			if (cnt == n * n) {
				break;
			}
		}
		cout << '#' << test_case << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n;j++) {
				cout << arr[i][j]<<' ';
			}
			cout << endl;
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}