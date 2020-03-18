
#include<iostream>
#include<vector>
int N, M;
using namespace std;
vector<int>chk;
//vector<int>arr[21];
vector<vector<int>>arr;
int maxi = 0;
void dfs(int from,int cnt) {
	if (maxi < cnt) { 
		maxi = cnt; 
	}
	chk[from] = 1;
	for (int i = 0; i < arr[from].size(); i++) {
		if (!chk[arr[from][i]]) {
			dfs(arr[from][i], cnt + 1);
		//	chk[arr[from][i]] = 0;
		}
	}
		chk[from] = 0;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N>>M;
		maxi = 0;
		if (M == 0) maxi = 0;
		else {
			arr = vector<vector<int >> (N + 1);

			for (int i = 0; i < M; i++) {
				int a, b;
				cin >> a >> b;
				arr[a].push_back(b);
				arr[b].push_back(a);
			}
			for (int i = 1; i <= N; i++) {
				chk = vector<int>(N+1, 0);
				if (!arr[i].empty()) {
					dfs(i, 1);
				}
			}
		}
		cout << '#' << test_case << ' ' << maxi << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}