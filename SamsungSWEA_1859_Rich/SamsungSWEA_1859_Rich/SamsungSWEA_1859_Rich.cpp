#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		long long int res = 0;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int chk=N-1;
		for (int i = N-2; i >=0; i--) {
			if (arr[chk] < arr[i]) {
				chk = i; continue;
			}
			else {
				res += arr[chk] - arr[i];
			}
		}

		printf("#%d %lld\n", test_case, res);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}