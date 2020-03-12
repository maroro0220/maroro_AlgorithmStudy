
#include<iostream>
#include<vector>

using namespace std;
vector<int>seq,chk;
int N, K,cnt;
void dfs(int idx, int sum) {
	if (K == sum) {
		cnt++;
		return;
	}
	else if (idx >= N) { return; }

	else {
		for (int i = idx; i < N; i++) {
			if (chk[i]) continue;
			else {
				chk[i] = 1;
				sum += seq[i];
				dfs(i, sum);
				sum -= seq[i];
				chk[i] = 0;
			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		seq = vector<int>(N);
		chk = vector<int>(N, 0);
		cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> seq[i];
		}
		dfs(0,0);
		
		cout << '#' << test_case << ' ' << cnt<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}