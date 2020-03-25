
#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<vector<int>> code;
int Find(int row, int idx) {
	int now = code[row][idx];
	vector<int>chk(4);
	if (now) return -1;
	int c=0,cnt=0;
	for (int i = idx; i < idx+7; i++) {
		if (now != code[row][i]) {
			now = code[row][i];
			chk[c] = cnt;
			c++;
			cnt = 1;
		}
		else cnt++;
	}
	chk[3] = cnt;
	if (chk[0] == 3 && chk[1] == 2 && chk[2] == 1 && chk[3] == 1) return 0;
	else if (chk[0] == 2 && chk[1] == 2 && chk[2] == 2 && chk[3] == 1) return 1;
	else if (chk[0] == 2 && chk[1] == 1 && chk[2] == 2 && chk[3] == 2) return 2;
	else if (chk[0] == 1 && chk[1] == 4 && chk[2] == 1 && chk[3] == 1) return 3;
	else if (chk[0] == 1 && chk[1] == 1 && chk[2] == 3 && chk[3] == 2) return 4;
	else if (chk[0] == 1 && chk[1] == 2 && chk[2] == 3 && chk[3] == 1) return 5;
	else if (chk[0] == 1 && chk[1] == 1 && chk[2] == 1 && chk[3] == 4) return 6;
	else if (chk[0] == 1 && chk[1] == 3 && chk[2] == 1 && chk[3] == 2) return 7;
	else if (chk[0] == 1 && chk[1] == 2 && chk[2] == 1 && chk[3] == 3) return 8;
	else if (chk[0] == 3 && chk[1] == 1 && chk[2] == 1 && chk[3] == 2) return 9;
	else return -1;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//int code[50][100];
	
	scanf("%d ", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//int code[50][100] = { 0 };
		int r,c;
		int sum = 0;
		scanf("%d %d ", &n, &m);
		code=vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &code[i][j]);
				if (code[i][j]) { r = i; c = j; }
			}
		} 
		int ret;
		vector<int>res;
		for (int i = c-56; i < m-7;) {
			sum = 0;
			ret = Find(r, i);
			if (ret != -1) {
				res.push_back(ret);
				i += 7;
			}
			else if (ret == -1)i++;

			if (res.size() == 8) {
				int cal = (res[0] + res[2] + res[4] + res[6]) * 3 + res[1] + res[3] + res[5] + res[7];
				if (cal % 10 == 0) {
					for (int i = 0; i < 8; i++) {
						sum += res[i];
					}
				}
			}
		}
		printf("#%d %d\n", test_case, sum);
	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}