#include<iostream>
#include<vector>
using namespace std;
#define INF 100001
void Print(vector<vector<int>> arr){
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 1; j < arr.size(); j++) {
			if (arr[i][j] == INF)cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}cout << '\n';
	}
}
int main() {
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<int>>city(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(!city[a][b]) city[a][b] = c;
		else {
			if (city[a][b] > c) city[a][b] = c;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (city[i][j] > city[i][k] + city[k][j]) {
					city[i][j] = city[i][k] + city[k][j];
				}
			}
		}
	}
	Print(city);
	return 0;
}