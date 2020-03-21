
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M;
		scanf("%d %d",&N,&M);
		vector<int>cookie(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cookie[i]);
		}
		sort(cookie.begin(), cookie.end());
		bool chk = false;
		int sum;
		int max = -1;
		for (int i = N - 1; i > 0; i--) {
			sum = 0;
			if (cookie[i] >= M) continue;
			sum += cookie[i];
			for (int j = i - 1; j >= 0; j--) {
				if (sum + cookie[j] <= M) { 
					//sum += cookie[j];  //if I use this, I need to sum-=cookie[j] after if
					if (max < sum+cookie[j]) max = sum+cookie[j];
					
				}
				
			}
		}
			printf("#%d %d\n",test_case,max);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}