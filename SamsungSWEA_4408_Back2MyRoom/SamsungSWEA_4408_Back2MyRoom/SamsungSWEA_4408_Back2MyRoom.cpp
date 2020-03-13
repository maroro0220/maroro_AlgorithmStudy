#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<int>chk(200, 0);
		int max = 0;
		int a, b;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			a = (a - 1) / 2;
			b = (b - 1) / 2;
			for (int i = a; i <= b; i++) {
				chk[i]++;
				if (max < chk[i]) max = chk[i];
			}
		}
		
		cout << '#' << test_case << ' ' << max << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}