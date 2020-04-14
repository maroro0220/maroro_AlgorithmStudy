
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		string str;
		cin >> N >> str;
		int mod = 0;
		int num = 1;
		if (N == 2) {
			mod = 0;
		}
		else {
			for (int i = str.size() - 1; i >= 0; i--) {
				mod = (mod+(str[i] - '0')% (N - 1)) % (N - 1);
				//num *= N;
			}
		}
		printf("#%d %d\n", test_case, mod);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}