
#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

int len = 7;
//map<int, bool> num;
set<int> num;
vector<vector<int>> arr(4, vector<int>(4, 0));
void dfs(int r, int c, int cnt,int n) {
	if (cnt == len) {
		//num.insert(make_pair(n, true));
		num.insert(n);
		return;
	}
	if (r >= 0 && r < 4 && c >= 0 && c < 4) {
		int tmp = n * 10 + arr[r][c];
		dfs(r + 1, c, cnt + 1,tmp);
		dfs(r, c + 1, cnt + 1,tmp);
		dfs(r - 1, c, cnt + 1,tmp);
		dfs(r, c - 1, cnt + 1,tmp);
	}
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4;j++) {
				dfs(i, j, 0, 0);
			}
		}
		/*
		for (auto it = num.begin(); it != num.end(); it++) {
			cout << it->first << endl;
		}
		*/
		cout << '#' << test_case << ' ' << num.size() << endl;;
		num.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}