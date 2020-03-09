
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
		<	�̵� ������ �������� �ٲ۴�.
		>	�̵� ������ ���������� �ٲ۴�.
		^	�̵� ������ �������� �ٲ۴�.
		v	�̵� ������ �Ʒ������� �ٲ۴�.
		_	�޸𸮿� 0�� ����Ǿ� ������ �̵� ������ ���������� �ٲٰ�, �ƴϸ� �������� �ٲ۴�.
		|	�޸𸮿� 0�� ����Ǿ� ������ �̵� ������ �Ʒ������� �ٲٰ�, �ƴϸ� �������� �ٲ۴�.
		?	�̵� ������ �����¿� �� �ϳ��� �������� �ٲ۴�. ������ �ٲ� Ȯ���� �� ���� �����ϴ�.
		.	�ƹ� �͵� ���� �ʴ´�.
		@	���α׷��� ������ �����Ѵ�.
		0~9	�޸𸮿� ���ڰ� ��Ÿ���� ���� �����Ѵ�.
		+	�޸𸮿� ����� ���� 1�� ���Ѵ�. ���� ���ϱ� �� ���� 15�̶�� 0���� �ٲ۴�.
		-	�޸𸮿� ����� ���� 1�� ����. ���� ���� �� ���� 0�̶�� 15�� �ٲ۴�.
		*/
		
		 res="NO";
		 //int a = 0, b = 0;
		//int dat = 0;
		//int dir = 1;
		 if(chk_a)dfs(0, 0, 0, 1);
		cout << '#' << test_case << ' ' << res << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}