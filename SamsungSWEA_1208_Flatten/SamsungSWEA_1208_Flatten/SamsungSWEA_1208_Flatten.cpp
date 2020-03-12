
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//cin >> T;
	T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int>box(100);
		int dump;
		cin >> dump;
		for (int i = 0; i < 100; i++) {
			cin >> box[i];
		}
		sort(box.begin(), box.end());
		while (dump--) {
			box[99]--;
			box[0]++;
			int idx_f = 0;
			int idx_b = 99;
			while (box[idx_f] >= box[idx_f+1]) {
				int tmp;
				tmp = box[idx_f+1];
				box[idx_f + 1] = box[idx_f];
				box[idx_f] = tmp;
				idx_f++;
			}
			while (box[idx_b]<=box[idx_b-1]) {
				int tmp;
				tmp = box[idx_b - 1];
				box[idx_b - 1] = box[idx_b];
				box[idx_b] = tmp;
				idx_b--;
			}
		}
		cout << '#' << test_case << ' ' << box[99] - box[0]<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}