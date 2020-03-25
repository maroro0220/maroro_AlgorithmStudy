
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long n, m;
		long long maxi=0;
		long long mid;
		cin >> n >> m;
		vector<int>npc(n);
		for (int i = 0; i < n; i++) {
			cin >> npc[i];
			if (maxi < npc[i]) maxi = npc[i];
		}

		//int time;
		long long mini = maxi * m;
		long long l = 1, r = m*maxi;
		while (l <= r)
		{
			long long people = 0;
			mid = (l + r) / 2;
			for (int i = 0; i < n; i++) {
				people += mid / npc[i];
			}
			if (people < m) {
				l = mid + 1;
			}
			else {
				if (mini > mid)mini = mid;
				r = mid - 1;
			}

		}
		
		/*
		//TIME OVER
		int time = 0;
		while (m>0) {
			for (int i = 0; i < n; i++) {
				if (time!=0&&(time % npc[i] == 0)) {
					m--;
				}
			}
			time++;
		}
		printf("#%d %d\n", test_case, time);
		*/
		printf("#%d %lld\n", test_case, mini);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}