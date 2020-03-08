
#include<iostream>
#include<vector>
using namespace std;
int r, c;
vector<vector<char>>arr; 

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> r >> c;
		arr= vector<vector<char>>(r, vector<char>(c));
		int mem[20][20][16][4] = { 0 };


		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[i][j];
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
		int a=0, b=0;
		int data=0;
		int dr[4] = { 0,0,-1,1 };
		int dc[4] = { -1,1,0,0 };
		int dir=1;
		int qd = 0;
		string res="NO";
		
		while (1) {
			if (arr[a][b] == '@') {
				res = "YES";
				break;
			}
			if (arr[a][b] >= '0' && arr[a][b] <= '9') {
				data = arr[a][b] - '0';
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
				if (!data) {
					dir = 1;
				}
				else {
					dir = 0;
				}
			}
			else if (arr[a][b] == '|') {
				if (!data ) {
					dir = 3;
				}
				else if (data) {
					dir = 2;
				}
			}
			else if (arr[a][b] == '?') {
				switch (qd)
				{
				case (0):
					dir = 0;
					break;
				case (1):
					dir = 1;
					break;
				case (2):
					dir = 2;
					break;
				case (3):
					dir = 3;
					break;
				default:
					break;
				}
				if (qd == 3) qd = 0;
				else qd ++ ;
			}
			else if (arr[a][b] == '.') {
				//nothing
			}
			if (arr[a][b] == '+') {
				if (data == 15) {
					data = 0;
				}
				else data++;
			}
			else if (arr[a][b] == '-') {
				if (data == 0) {
					data = 15;
				}
				else data--;
			}
			if (mem[a][b][data][dir]==5) {
				cout << a << ' ' << b << ' ' << data << ' ' << dir << '=' << mem[a][b][data][dir] << endl;
				
				break;
			}
			else {
				cout << a << ' ' << b << ' ' << data << ' ' << dir <<'='<< mem[a][b][data][dir] << endl;

				mem[a][b][data][dir] ++;
			}if (a + dr[dir] >= r) {
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
		cout << '#' << test_case << ' ' << res << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}