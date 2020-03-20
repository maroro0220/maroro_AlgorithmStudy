
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
		int k;
		cin >> k;
		vector<int>v;
		int tmp;
		int sum = 0;
		for (int i = 0; i < k; i++) {
			cin >> tmp;
			if (tmp) {
				v.push_back(tmp);
				sum += tmp;
			}
			else if (!tmp) { 
				sum-=v.back();
				v.pop_back();
			}
		}
		printf("#%d %d\n", test_case, sum);

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}