#include <iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> grap[101010];
int node[101010][18];
int dep[101010];
void bfs(int s) {
	queue<int> q;
	q.push(s);
	dep[s] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < grap[now].size(); ++i) {
			int nx = grap[now][i];
			if (dep[nx] == 0) {
				dep[nx] = dep[now] + 1;
				node[nx][1] = now;
				q.push(nx);
			}
		}
	}
}
void getP(int n) {
	//for (int j = 2; (1 << j) <= n; ++j) {
	for (int j = 2; j < n; j++) {
		for (int i = 1; i <= n; ++i) {
			if (node[i][j - 1] > 1)
				node[i][j] = node[node[i][j - 1]][1];
		}
	}
}
int LCA(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	if (dep[a] != dep[b]) {
		//for (int i = 18; i >= 1; --i) {
			//while (dep[a]  > dep[b]){
			//	a = node[a][1];
		//}
		a = node[a][dep[a] - dep[b]];

	}
	if (a == b) {
		return a;
	}
	else {
		//for (int i = 18; i >= 1; --i) {
		//	if (dep[a] - (1 << (i-1)) >= 0 && node[a][i] != node[b][i]) {
		while (node[a][1] != node[b][1]) {
			a = node[a][1];
			b = node[b][1];

		}
	}
	return node[a][1];
}
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		grap[a].push_back(b);
		grap[b].push_back(a);
	}
	bfs(1);
	getP(n);


	int m;
	scanf("%d", &m);
	//while (m--) {
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", LCA(a, b));
	}
	return 0;
}