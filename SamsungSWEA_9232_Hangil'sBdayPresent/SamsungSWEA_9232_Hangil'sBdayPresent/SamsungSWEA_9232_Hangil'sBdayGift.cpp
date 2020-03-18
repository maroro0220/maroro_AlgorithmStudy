#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, q;
		int res = 0;
		cin >> n >> q;
		vector<int>hole(n + 1, 0);
		int tmp = 1e9;
		hole[0] = tmp;
		//vector<int>disk(q);
		for (int i = 1; i <= n; i++) {
			cin >> hole[i];
			if (hole[i - 1] < hole[i]) hole[i] = hole[i - 1];
		}
		int disk;
		int j = n;
		bool chk = true;
		for (int i = 0; i < q; i++) {
			cin >> disk;

			for (; j > 0; ) {
				if (j ==1) {
					if (disk == hole[j]) res = 0;
					else res = -1; 
					break;
				}
				if (hole[j] < disk) j--;
				else if (hole[j] >= disk) {
					
					break;
				}
			}
				res = --j;
				
		}
		//res = (chk) ? res+1 : 0;
		cout << '#' << test_case << ' ' << res+1 << endl;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}