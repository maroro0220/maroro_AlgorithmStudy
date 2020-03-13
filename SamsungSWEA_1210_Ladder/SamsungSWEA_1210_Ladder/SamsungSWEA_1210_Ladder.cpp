#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//cin >> T;
	T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int em;
		cin >> em;
		vector<vector<int>> lad(100, vector<int>(100, 0));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> lad[i][j];
			}
		}
		int res = 0;
		for (int i = 0; i < 100; i++) {
			if (!lad[0][i]) continue;
			int r = 0, c = i;
			for (r; r < 100;) {
				r++;
				if (r == 99) {
					if (lad[r][c] == 2) {
						res = i;
					}
					break;
				}
				if (c - 1 >= 0 && lad[r][c - 1]) {
					while (c - 1 >= 0 && lad[r][c - 1])c--;
				}
				else if (c + 1 < 100 && lad[r][c + 1]) {
					while (c + 1 < 100 && lad[r][c + 1])c++;
				}

			}
			if (res) break;
		}
		cout << '#' << test_case << ' ' << res << endl;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}