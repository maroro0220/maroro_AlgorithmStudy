
#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> map;
int N;
int cnt;
int dy[6] = {0,0,-1,-1,+1,+1};
int dx[6] = {-1,+1,-1,+1,-1,+1};
bool chk(int r,int c,vector<vector<int>> mm) {
	int rtmp,ctmp;
	for (int i = 0; i < N; i++) {
		rtmp = r - i;
		if (rtmp >= 0) {
			if (mm[rtmp][c]) return false;
		}
	}	for (int i = 0; i < N; i++) {
		rtmp = r + i;
		if (rtmp <N) {
			if (mm[rtmp][c]) return false;
		}
	}
	for (int i = 0; i < N; i++) {
		ctmp = c - i;
		if (ctmp >= 0 ) {
			if(mm[r][ctmp]) return false ;
		}
	}
	for (int i = 0; i < N; i++) {
		ctmp = c + i;
		if (c + i < N) {
			if(mm[r][ctmp]) return false;
		}
	}
	for (int i = 0; i < N; i++) {
		rtmp = r - i; ctmp = c - i;
		if (rtmp >= 0&& ctmp >= 0 ) {
			if(mm[rtmp][ctmp])return false ;
		}
	}
	for (int i = 0; i < N; i++) {
		rtmp = r - i; ctmp = c + i;
		if (rtmp >= 0  && ctmp < N) {
			if(mm[rtmp][ctmp])return false ;
		}
		
	}
	for (int i = 0; i < N; i++) {
		rtmp = r + i; ctmp = c - i;
		if (rtmp < N && ctmp >= 0 ) {
			if (mm[rtmp][ctmp]) return false ;
		}
	}
	for (int i = 0; i < N; i++) {
		rtmp = r + i; ctmp = c + i;
		if (rtmp < N && ctmp < N) {
			if(mm[rtmp][ctmp])return false ;
		}
	}
	return true;
}

void dfs(int r,vector<vector<int>> m) {
	if (r == N) {
		cnt++;
		return;
	}
	else {
		for (int j = 0; j < N; j++) {
			if (m[r][j]) continue;
			if (!m[r][j]) {
				if (!chk(r, j, m)) {
					continue;
				}
				else {
					m[r][j] = r + 1;
					dfs(r + 1, m);
					m[r][j] = 0;
				}
			}
		}
	return;
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		map = vector<vector<int>>(N, vector<int>(N, 0));

		dfs(0,map);

		cout << '#' << test_case << ' ' << cnt << endl;
		cnt = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}