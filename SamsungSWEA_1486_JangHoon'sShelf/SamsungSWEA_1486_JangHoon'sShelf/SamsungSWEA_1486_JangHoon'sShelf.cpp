#include<iostream>

using namespace std;
int N, B;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> B;
		int* people = new int[N];
		//int* chk = new int[1 << N]{0};
		int min = 0;
		for (int i = 0; i < N; i++) {
			cin >> people[i];
			min += people[i];
		}
		for (int i = 1; i < (1 << N); i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) {
					sum += people[j];
					if(min<sum){
						break;
					}
				}
			}
			if (sum >= B) {
				min = min < sum ? min : sum;
			}
		}
		printf("#%d %d\n", test_case,min-B);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}