
#include<iostream>

using namespace std;
//int** arr;
//int** chk;
int arr[100][100];
int chk[100][100];
pair<int, int> start, goal;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
bool res = false;
bool Dfs(int r, int c) {
	if (r == goal.first && c == goal.second) {
		res = true;
		return res;
	}
	chk[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if (next_r < 0 || next_r >= 100 || next_c < 0 || next_c >= 100 || arr[next_r][next_c] == 1) continue;
		if ((arr[next_r][next_c] == 0 || arr[next_r][next_c]==3) && chk[next_r][next_c] == 0) {
			chk[next_r][next_c] = 1;
			Dfs(next_r, next_c);
			//chk[next_r][next_c] = 0; 
		}
	}
	return res;
}
int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		res = false;
		int tmp;
		scanf("%d", &tmp);
		/*
		arr = new int*[100];
		chk = new int*[100];
		for (int i = 0; i < 100; i++) {
			arr[i] = new int[100];
			chk[i] = new int[100];
			memset(arr[i], 0, sizeof(int)*100);
			memset(chk[i], 0, sizeof(int)*100);
		}*/
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				chk[i][j] = 0;
			}
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d ", &arr[i][j]);
				if (arr[i][j] == 2) {
					start.first = i;
					start.second = j;
				}
				else if (arr[i][j] == 3) {
					goal.first = i;
					goal.second = j;
				}
			}
		}
		if (Dfs(start.first, start.second)) {
			printf("#%d 1\n", test_case);
		}
		else {
			printf("#%d 0\n", test_case);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}