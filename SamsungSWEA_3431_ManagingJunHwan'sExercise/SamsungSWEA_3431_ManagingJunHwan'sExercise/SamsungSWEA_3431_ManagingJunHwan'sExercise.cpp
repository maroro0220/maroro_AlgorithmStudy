
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long L, U, X;
		scanf("%lld %lld %lld", &L, &U, &X); //L<X<U
		if (X <= L) {
			printf("#%d %lld\n", test_case, L - X);
		}
		else if (X < U) {
			printf("#%d 0\n", test_case);
		}
		else if (X >U) {
			printf("#%d -1\n", test_case);
		}
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}