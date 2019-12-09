#include<vector>
#include<iostream>
using namespace std;

int r, c, cnt;
void Z(int n, int x, int y) {
	if (n == (1 << 1)) {
		if (x == c && y == r) {
			cout << cnt;
			return;
		}
		cnt++;
		if (x+1 == c && y == r) {
			cout << cnt;
			return;
		}
		cnt++;
		if (x == c && y+1 == r) {
			cout << cnt;
			return;
		}
		cnt++;
		if (x+1 == c && y+1 == r) {
			cout << cnt;
			return;
		}
		cnt++;
		return;
	}
	else {
		Z(n / 2, x, y);
		Z(n / 2, x+n/2, y);
		Z(n / 2, x, y+n / 2);
		Z(n / 2, x+ n / 2, y+n / 2);

	}
	return;
}

int main() {
	int N;
	cin >> N >> r >> c;
	Z(1 << N, 0, 0);
	return 0;
}