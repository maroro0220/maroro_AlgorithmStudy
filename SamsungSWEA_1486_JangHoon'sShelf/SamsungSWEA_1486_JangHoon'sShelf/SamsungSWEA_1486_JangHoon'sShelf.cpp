#include<iostream>

using namespace std;
int N, B,mini;
/*
//Time over
void DFS(int idx,int cnt,int n, int* pep, int* chk,int sum) {
	if (n == cnt) {
		//printf("%d\n", sum);
		if (sum >= B) {
			mini = mini < sum ? mini : sum;
		}
		return;
	}
	chk[idx] = 1;
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = 1;
		sum += pep[i];
		DFS(i, cnt + 1, n, pep, chk, sum);
		sum -= pep[i];
		chk[i] = 0;
		
	}

	return;
}
*/
void DFS(int cnt, int sum, int* pep) {
	if (cnt == N) {
		if (sum >= B && mini>sum) {
			mini = sum;
		}
		return;
	}
	DFS(cnt + 1, sum + pep[cnt], pep);
	DFS(cnt + 1, sum , pep);
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> B;
		int* people = new int[N];
		mini = 0;
		for (int i = 0; i < N; i++) {
			cin >> people[i];
			mini += people[i];
		}
		DFS(0, 0, people);
		/*
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
		*/

		printf("#%d %d\n", test_case,mini-B);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}