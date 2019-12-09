#include<iostream>
#include<vector>

using namespace std;
vector<string>input;
void Quad(int n, int c, int r) {
	if (n == 1) {
		cout << input[r][c];
		return;
	}
	bool zero = true, one = true;
	for (int i = r; i < r+n; i++) {
		for (int j = c; j < c+n; j++) {
			if (input[i][j] == '0') {
				one = false;
			}
			else if (input[i][j] == '1') {
				zero = false;
			}
		}
	}
	if (one) {
		cout << '1';
	}
	else if (zero) {
		cout << '0';
	}
	else {
		cout << '(';
		Quad(n / 2, c, r);
		Quad(n / 2, c+n/2, r);
		Quad(n / 2, c, r+n/2);
		Quad(n / 2, c + n / 2, r + n / 2);
		cout << ')';
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	Quad(n, 0, 0);
	return 0;
}