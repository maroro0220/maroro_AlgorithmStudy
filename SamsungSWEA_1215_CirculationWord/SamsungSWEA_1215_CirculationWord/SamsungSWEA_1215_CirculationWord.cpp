
#include<iostream>
#include<vector>
using namespace std;
int ans;
vector<vector<char>> words(8,vector<char>(8));
bool ChkCol(int r, int c, int N) {
	for (int i = 0; i < N / 2; i++) {
		if (words[r][c + i] != words[r][c + (N - 1) - i]) return false;
	}
	return true;
}
bool ChkRow(int r, int c, int N) {
	for (int i = 0; i < N / 2; i++) {
		if (words[r+i][c] != words[r + (N - 1) - i][c ]) return false;
	}
	return true;
}
void Chk(int r, int c, int N) {
	if (c+N-1<8) {
		if (ChkCol(r, c, N)) {
			ans++;
		}
	}
	if (r + N - 1 < 8) {
		if (ChkRow(r, c, N)) {
			ans++;
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		scanf("%d ",&N);
		ans = 0;
		if (N == 1) {
			printf("#%d %d\n",test_case,64);
		}
		else {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					scanf(" %c", &words[i][j]);
				}
			}
			for (int i = 0; i < 8 ; i++) {
				for (int j = 0; j < 8; j++) {
					Chk(i, j, N);
				}
			}
		}
		printf("#%d %d\n", test_case, ans);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}