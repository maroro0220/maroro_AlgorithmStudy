
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//cin >> T;
	scanf(" %d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int sum = 0;
		scanf(" %d", &N);
		vector<vector<int>>farm(N, vector<int>(N));
		vector<vector<int>>chk(N, vector<int>(N,0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &farm[i][j]);
				//sum += farm[i][j];
			}
		}
		//this is better
		for (int i = 0; i < N / 2; i++) {
			sum += farm[i][N / 2];
			sum += farm[N - 1 - i][N / 2];
			for (int j = 1; j <= i; j++) {
				sum += (farm[i][N / 2+j]+ farm[i][N / 2-j]);
				sum += (farm[N - 1 - i][N / 2+j]+ farm[N - 1 - i][N / 2-j]);
			}
		}
		for (int i = 0; i < N; i++) {
			sum += farm[N / 2][i];
		}
		/*
		for (int i = 0; i < N; i++) {
			if (i < N / 2) {
				sum += farm[i][N / 2];
				for (int j = 1; j <= i; j++) {
					sum += (farm[i][N / 2 - j] + farm[i][N / 2 + j]);
				}
			}
			else if (i == N / 2) {
				sum += farm[i][N / 2];
				for (int j = 1; j <= i; j++) {
					sum += (farm[i][N / 2 - j] + farm[i][N / 2 + j]);
				}
			}
			else if(i>N/2 && i<N) {
				sum += farm[i][N / 2];
				for (int j = 1; j <= (N - 1 - i); j++) {
					sum += (farm[i][N / 2 - j] + farm[i][N / 2 + j]);
				}
			}
		}
		*/
		
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d ", chk[i][j]);
			}
			printf("\n");
		}
		*/
		printf("#%d %d\n", test_case, sum);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}