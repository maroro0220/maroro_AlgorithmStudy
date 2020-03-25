
#include<iostream>

using namespace std;

int M;
int Func(int n,int cnt) {
	if (cnt == M) return 1;

	return n * Func(n, cnt + 1);
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		int tmp;
		cin >> tmp;
		cin >> n >> M;
		printf("#%d %d\n",tmp,Func(n, 0));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}