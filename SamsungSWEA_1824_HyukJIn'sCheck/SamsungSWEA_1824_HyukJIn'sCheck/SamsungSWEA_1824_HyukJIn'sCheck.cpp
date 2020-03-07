
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int r, c;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> r >> c;
		vector<vector<char>>arr(r, vector<char>(c));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> arr[i][j];
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
		int a=0, b=0;
		int mem;
		int dr[4] = { 0,0,-1,1 };
		int dc[4] = { -1,1,0,0 };
		int dir=1;
		while (arr[a][b] != '@') {
			
			if (arr[a][b] >= '0' && arr[a][b] <= '9') {
				mem = arr[a][b] - '0';
			}
			else if (arr[a][b] == '<') {
				dir = 0;
			}
			else if (arr[a][b] == '>') {
				dir = 1;
			}
			else if (arr[a][b] == '^') {
				dir =2;
			}
			else if (arr[a][b] == 'v') {
				dir = 3;
			}
			else if (arr[a][b]=='_') {
				if (mem == '0') {
					dir = 1;
				}
				else if (mem != '0') {
					dir = 0;
				}
			}
			else if (arr[a][b] == '|') {
				if (mem == '0') {
					dir = 3;
				}
				else if (mem != '0') {
					dir = 2;
				}
			}
			else if (arr[a][b] == '?') {
				srand((unsigned int)time(NULL));
				dir=int(rand()%4);
			}
			else if (arr[a][b] == '.') {
			//nothing
			}
			else if (arr[a][b] == '+') {
				if (mem == 15) {
					mem = 0;
				}
				else mem++;
			}
			else if (arr[a][b] == '-') {
				if (mem == 0) {
					mem = 15;
				}
				else mem--;
			}
		}

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}