
#include<iostream>
#include<vector>
using namespace std;
int r, c;
vector<vector<char>>arr;
int mem[20][20][16][4] = { 0 };

//int dat;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };
//int dir = 1;
int qd ;
string res;
bool dfs(int a,int b, int dat, int dir) {
	while (1) {
		if (arr[a][b] == '@') {
			res = "YES";
			return true;
		}if (mem[a][b][dat][dir]) {
			//cout << a << ' ' << b << ' ' << dat << ' ' << dir << '=' << mem[a][b][dat][dir] << endl;
			return false;
		}
		else {
			//cout << a << ' ' << b << ' ' << dat << ' ' << dir <<'='<< mem[a][b][dat][dir] << endl;
			mem[a][b][dat][dir] ++;
		}
		if (arr[a][b] >= '0' && arr[a][b] <= '9') {
			dat = arr[a][b] - '0';
		}
		else if (arr[a][b] == '<') {
			dir = 0;
		}
		else if (arr[a][b] == '>') {
			dir = 1;
		}
		else if (arr[a][b] == '^') {
			dir = 2;
		}
		else if (arr[a][b] == 'v') {
			dir = 3;
		}
		else if (arr[a][b] == '_') {
			if (!dat) {
				dir = 1;
			}
			else {
				dir = 0;
			}
		}
		else if (arr[a][b] == '|') {
			if (!dat) {
				dir = 3;
			}
			else if (dat) {
				dir = 2;
			}
		}
		else if (arr[a][b] == '?') {
			for (int i = 0; i < 4; i++) {
				int n_a = a + dr[i];
				int n_b = b + dc[i];
				if ( n_a>= r) {
					n_a = 0;
				}
				else if (n_a < 0) {
					n_a = r - 1;
				}
				
				if (n_b >= c) {
					n_b = 0;
				}
				else if (n_b < 0) {
					n_b = c - 1;
				}
			//for (int i = 0; i < 4; i++) {
				//cout << a << ' ' << b << ' ' << dat << ' ' << dir << '=' << mem[a][b][dat][dir] << endl;
				if (dfs(n_a, n_b, dat, i)) {
					break;
				}
			}
				//if (dfs(a, b, dat, i)) { return true; }
			//}
		}
		else if (arr[a][b] == '.') {
			//nothing
		}
		else if (arr[a][b] == '+') {
			if (dat == 15) {
				dat = 0;
			}
			else dat++;
		}
		else if (arr[a][b] == '-') {
			if (dat == 0) {
				dat = 15;
			}
			else dat--;
		}
		
		if (a + dr[dir] >= r) {
			a = 0;
		}
		else if (a + dr[dir] < 0) {
			a = r - 1;
		}
		else {
			a += dr[dir];
		}
		if (b + dc[dir] >= c) {
			b = 0;
		}
		else if (b + dc[dir] < 0) {
			b = c - 1;
		}
		else {
			b += dc[dir];
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
		cin >> r >> c;
		arr= vector<vector<char>>(r, vector<char>(c));
		bool chk_a = false;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '@') chk_a = true;
				for (int k = 0; k < 16; k++) {
					for (int l = 0; l < 4; l++) {
						mem[i][j][k][l] = 0;
					}
				}
			}
		}
		/*
		<	이동 방향을 왼쪽으로 바꾼다.
		>	이동 방향을 오른쪽으로 바꾼다.
		^	이동 방향을 위쪽으로 바꾼다.
		v	이동 방향을 아래쪽으로 바꾼다.
		_	메모리에 0이 저장되어 있으면 이동 방향을 오른쪽으로 바꾸고, 아니면 왼쪽으로 바꾼다.
		|	메모리에 0이 저장되어 있으면 이동 방향을 아래쪽으로 바꾸고, 아니면 위쪽으로 바꾼다.
		?	이동 방향을 상하좌우 중 하나로 무작위로 바꾼다. 방향이 바뀔 확률은 네 방향 동일하다.
		.	아무 것도 하지 않는다.
		@	프로그램의 실행을 정지한다.
		0~9	메모리에 문자가 나타내는 값을 저장한다.
		+	메모리에 저장된 값에 1을 더한다. 만약 더하기 전 값이 15이라면 0으로 바꾼다.
		-	메모리에 저장된 값에 1을 뺀다. 만약 빼기 전 값이 0이라면 15로 바꾼다.
		*/
		
		 res="NO";
		 //int a = 0, b = 0;
		//int dat = 0;
		//int dir = 1;
		 if(chk_a)dfs(0, 0, 0, 1);
		cout << '#' << test_case << ' ' << res << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
//other people's
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int N, M;
int chk[20][20][4][16];
char map[20][20];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int finished = 0;
int qx[26000];
int qy[26000];
int qd[26000];
int qn[26000];
int qf[26000];
int st, ed;
int main() {

	int test_case, t;
	int i, j, k, l;

	scanf("%d", &test_case);

	for (t = 1; t <= test_case; ++t) {

		finished = 0;
		scanf("%d %d", &N, &M);
		for (i = 0; i < N; ++i) {
			for (j = 0; j < M; ++j) {
				scanf(" %c", &map[i][j]);
				for (k = 0; k < 4; ++k) {
					for (l = 0; l <= 15; ++l) {
						chk[i][j][k][l] = 0;
					}
				}
			}
		}
		st = ed = 0;
		qx[++st] = 0;
		qy[st] = 0;
		qd[st] = 0;
		qn[st] = 0;
		qf[st] = -1;
		int x, y, d, n;
		int now = 0;
		char c;
		while (1) {
			ed++;
			if (qx[ed] == 2 && qy[ed] == 4) {
				now++;
			}
			if (map[qx[ed]][qy[ed]] == '@') {
				printf("#%d YES\n", t);
				break;
			}
			if (st < ed) {
				printf("#%d NO\n", t);
				break;
			}
			x = qx[ed];
			y = qy[ed];
			d = qd[ed];
			n = qn[ed];
			c = map[qx[ed]][qy[ed]];

			if ('0' <= c && c <= '9') {
				n = c - '0';
			}
			else if (c == '<') {
				d = 2;
			}
			else if (c == '>') {
				d = 0;
			}
			else if (c == 'v') {
				d = 3;
			}
			else if (c == '^') {
				d = 1;
			}
			else if (c == '_') {
				if (n == 0) {
					d = 0;
				}
				else {
					d = 2;
				}
			}
			else if (c == '|') {
				if (n == 0) {
					d = 3;
				}
				else {
					d = 1;
				}
			}
			else if (c == '+') {
				n++;
				if (n == 16) {
					n = 0;
				}
			}
			else if (c == '-') {
				n--;
				if (n == -1) {
					n = 15;
				}
			}
			int nx, ny;
			if (c == '?') {
				for (i = 0; i < 4; ++i) {
					nx = (x + dx[i] + N) % N;
					ny = (y + dy[i] + M) % M;
					if (chk[nx][ny][i][n] == 0) {
						chk[nx][ny][i][n] = 1;
						qx[++st] = nx;
						qy[st] = ny;
						qd[st] = i;
						qn[st] = n;
						qf[st] = ed;
					}
				}
			}
			else {
				nx = (x + dx[d] + N) % N;
				ny = (y + dy[d] + M) % M;
				if (chk[nx][ny][d][n] == 0) {
					chk[nx][ny][d][n] = 1;
					qx[++st] = nx;
					qy[st] = ny;
					qd[st] = d;
					qn[st] = n;
					qf[st] = ed;
				}
			}
		}
	}
}

*/