
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);//customer, sec, num of fishbread
		vector<int>cust_t;
		//int* cust = new int[11111]{ 0 };
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			//cust[tmp]++;
			cust_t.push_back(tmp);
		}
		sort(cust_t.begin(), cust_t.end());
	//	for (int i = 0; i < cust_t.size(); i++) {
	//		cust[cust_t.front()]++;
	//	}
		int c = 0;
		int Bnum = 0;
		bool chk = true;
		for (int i = 0; i < 11112; i++) {
			int now = cust_t[c];
			if (i>0&&i % m == 0) {
				Bnum += k;
			}
			if (now <= i) {

				while (now == cust_t[c]) {
					Bnum--;
					c++;
					if (c == cust_t.size()) break;
				}
				if (Bnum < 0) {
					chk = false;
					break;
				}
			}
			if (chk && c == cust_t.size()) { 
				chk = true;
				break; 
			}
		}
		if (chk) {
			printf("#%d Possible\n", test_case);
		}
		else {
			printf("#%d Impossible\n", test_case);
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}