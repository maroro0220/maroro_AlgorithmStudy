#include<iostream>
#include<vector>

using namespace std;
vector<vector<char>> arr;
void Star(int n,int r, int c) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i ==1 && j==1) arr[r + i][c + j] = ' ';
				else  arr[r + i][c + j] = '*';
			}
		}
		return;
	}
	int div = n / 3;
//	for (int a = 0; a < 3; a++) {
//		for (int b = 0; b < 3; b++) {
//			if (a == 1 && b == 1) continue;
	Star(div, r + div * 0, c + div * 0);
	Star(div, r + div * 0, c + div * 1);
	Star(div, r + div * 0, c + div * 2);
	Star(div, r + div * 1, c + div * 0);
//	Star(div, r + div * 1, c + div * 1);
	Star(div, r + div * 1, c + div * 2);
	Star(div, r + div * 2, c + div * 0);
	Star(div, r + div * 2, c + div * 1);
	Star(div, r + div * 2, c + div * 2);
	//		}
//	}
	/*
	if (n == 1) {
		arr[r][c] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) { continue; }
			Star(div, r+(div*i), c+(div*j));
		}
		//cout << '\n';
	}
	*/
}

int main() {

	int num;
	cin >> num;
	arr = vector<vector<char>>(num, vector<char>(num,' '));
	Star(num, 0, 0);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}