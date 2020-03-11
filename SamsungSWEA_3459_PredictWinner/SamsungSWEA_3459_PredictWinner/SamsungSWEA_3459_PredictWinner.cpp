
#include<iostream>
#include<stdio.h>
//#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long N;
		scanf("%lld", &N);
		string res;
		if (N < 4) {
			if (N == 1) {
				printf("#%d Bob\n", test_case);//res = "Bob"; 
			}
			else printf("#%d Alice\n", test_case); //res = "Alice";
		}
		else {
			int depth = 2;
			while (1) {
				if (N >= (1ll << depth) && N < (1ll << (depth + 1))) break;
				depth++;
			}
			long long x = 1ll;
			if (depth % 2) {
				for (int i = 1; i <= depth; i++) {
					if (i % 2) {
						x =x<< 1;
					}
					else {
						x = (x << 1) + 1;
					}
				}					
				if (x <= N) printf("#%d Alice\n", test_case);//res = "Alice";
				else printf("#%d Bob\n", test_case); //res = "Bob";
			}
			else {
				for (int i = 1; i <= depth; i++) {
					if (i % 2) {
						x = (x << 1) + 1;
					}
					else {
						x =x<< 1;
					}
				}
				if (x > N) printf("#%d Alice\n", test_case);//res = "Alice";
				else printf("#%d Bob\n", test_case);//res = "Bob";
			}
		}
		
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}