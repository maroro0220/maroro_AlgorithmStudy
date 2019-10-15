#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> su(9, vector<int>(9));

vector<pair<int,int>> space;
void chk(int y, int x) {
	for (int i = 0; i < 9; i++) {
		
	}
}
void dfs(int idx) {
	vector<int> row(10, 0),col(10,0),sq(10,0);
	vector<int>chk(10, 0);
	if (idx == space.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << su[i][j] << ' ';
			}
			cout << endl;
		}

		exit(0);
		//return;
	}
	for (int i = 0; i < 9; i++) {
		if (su[space[idx].first][i]) {
			row[su[space[idx].first][i]] = 1;
		}
		if (su[i][space[idx].second]) {
			col[su[i][space[idx].second]] = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (su[i+(space[idx].first/3)*3][j+(space[idx].second / 3) * 3]) {
				sq[su[i + (space[idx].first / 3) * 3][j + (space[idx].second / 3) * 3]] = 1;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		if (!col[i] && !row[i] && !sq[i]) {
			col[i] = 1;
			row[i] = 1;
			sq[i] = 1;
			su[space[idx].first][space[idx].second] = i;
			dfs(idx + 1);
			su[space[idx].first][space[idx].second] = 0;
			col[i] = 0;
			row[i] = 0;
			sq[i] = 0;
		}
	}
}
int main() {

	for (int a = 0; a < 9; a++) {
		for (int b = 0; b < 9; b++) {
			cin >> su[a][b];
			if (!su[a][b]) {
				space.push_back({ a,b });
			}
		}
	}
	cout << endl;
	dfs(0);

	return 0;
}