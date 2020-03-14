
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int empty;
		cin >> empty;

		int arr[100][100];
		int col[100] = { 0 }, row[100] = { 0 };
		int left = 0, right = 0;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				if (i == j) left += arr[i][j];
				if ((i + j) == 99) right += arr[i][j];
				row[j] += arr[i][j];
				col[i] += arr[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i < 100; i++) {
			if (max < row[i]) max = row[i];
			if (max < col[i])max = col[i];
		}
		if (max < right) max = right;
		if (max < left)max = left;
		cout << '#' << test_case << ' ' << max << endl;


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}