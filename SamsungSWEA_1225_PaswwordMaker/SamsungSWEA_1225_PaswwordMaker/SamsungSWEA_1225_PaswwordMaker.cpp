
#include<iostream>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int empt;
		scanf("%d", &empt);
		queue<int> q;
		int tmp;
		for (int i = 0; i < 8; i++) {
			scanf("%d", &tmp);
			q.push(tmp);
		}
		int f;
		bool chk = true;
		while (chk) {
			for (int i = 1; i <= 5; i++) {
				f = q.front();
				q.pop();
				if ((f - i) <= 0) {
					chk = false;
					q.push(0);
					break;
				}
				q.push(f - i);
				
			}
		}
		printf("#%d", test_case);
		for (int i = 0; i < 8; i++) {
			printf(" %d", q.front());
			q.pop();
		}
		printf("\n");

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}