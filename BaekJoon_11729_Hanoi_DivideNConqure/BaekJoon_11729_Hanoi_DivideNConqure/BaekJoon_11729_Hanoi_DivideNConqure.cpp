#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> path;
int cnt;
void move(int from, int to) {
	path.push_back({ from,to });
	cnt++;
}
void hanoi(int n,int from, int by, int to){
	if (n == 1) {
		move(from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}
int main() {
	int N;
	cin >> N;
	hanoi(N, 1, 2, 3);
	cout << cnt<<'\n';
	for (int i = 0; i < path.size(); i++) {
		cout << path[i].first << ' ' << path[i].second << '\n';
	}
	return 0;
}