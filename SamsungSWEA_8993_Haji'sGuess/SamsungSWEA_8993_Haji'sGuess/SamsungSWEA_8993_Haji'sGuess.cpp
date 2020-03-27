
#include<iostream>
//#include<map>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		//map<long long,int>arr;
		long long n;
		scanf("%lld", &n);
		//bool res=true;

		//accept
		bool res;
		if (n % 2 == 1) res = false;
		else {
			while (n > 1) {
				if (n % 2 == 1) { res = false; break; }
				else res = true;
				n /= 2;
			}
		}
		/*
		//impossible. because when n is Maximum(100000000000000) it happen overflow. n/2 -> n*3+3 here.
		while (n > 1) {
			if (arr[n]) {
				printf("#%d NO\n",test_case);
				res = false;
				break;
			}
			arr[n] = 1;
			printf("%d ", n);
			if (n % 2 == 0)n = n / 2;
			else n = n * 3 + 3;
		}

		if (res) {
			printf("#%d YES\n", test_case);
		}*/

		//accept
		if (res) {
			printf("#%d YES\n", test_case);
		}
		else {
			printf("#%d NO\n", test_case);
		}


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}