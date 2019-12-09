#include<vector>
#include<iostream>

using namespace std;

int cnt_minus, cnt_zero, cnt_one;
vector<vector<int>> paper;
void Cnt(int r, int c) {
	if (paper[r][c] == -1) {
		cnt_minus++;
	}else if (paper[r][c] == 1) {
		cnt_one++;
	}else if (paper[r][c] == 0) {
		cnt_zero++;
	}
}
void Paper(int n,int r, int c) {
	if (n == 1) {
		Cnt(r, c);
		return;
	}
	bool zero=true, one=true, minus=true;
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (paper[i][j] == 0) {
				one = false;
				minus = false;
			}
			else if (paper[i][j] == 1) {
				zero = false;
				minus = false;
			}
			else if (paper[i][j] == -1) {
				one = false;
				zero = false;
			}
		}
	}
	if (zero) {
		cnt_zero++;
	}
	else if (one) {
		cnt_one++;
	}
	else if (minus) {
		cnt_minus++;
	}
	else {
		Paper(n / 3, r, c);
		Paper(n / 3, r, c + n / 3);
		Paper(n / 3, r, c + n * 2 / 3);
		Paper(n / 3, r + n / 3, c);
		Paper(n / 3, r + n / 3, c + n / 3);
		Paper(n / 3, r + n / 3, c + n * 2 / 3);
		Paper(n / 3, r + n*2 / 3, c);
		Paper(n / 3, r + n*2 / 3, c + n / 3);
		Paper(n / 3, r + n*2 / 3, c + n * 2 / 3);
	}
}

int main() {
	int n;
	cin >> n;
	paper = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	Paper(n, 0, 0);
	cout << cnt_minus << '\n' << cnt_zero << '\n' << cnt_one << '\n';
	return 0;
}