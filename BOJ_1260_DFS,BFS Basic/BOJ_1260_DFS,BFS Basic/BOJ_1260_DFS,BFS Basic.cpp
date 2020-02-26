/*#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, V;
vector<int> chkd(1001, 0), chkb(1001, 0);
vector<vector<int>> d(1001);
//vector<int> d[1001];
//vector<int>con;
void dfs(int v) {

	//cout <<v<<' ';
	printf("%d ", v);
	chkd[v] = 1;
	for (int i = 0; i < d[v].size(); i++) {
		if (!chkd[d[v][i]]) {
			dfs(d[v][i]);
		}
	}
}
void bfs(int v) {
	queue<int> b;
	b.push(v);
	chkb[v] = 1;
	while (!b.empty()) {
		int tmp = b.front();
		b.pop();
		//cout << tmp<< ' ';
		printf("%d ", tmp);
		for (int i = 0; i < d[tmp].size(); i++) {
			if (!chkb[d[tmp][i]]) {
				chkb[d[tmp][i]] = 1;
				b.push(d[tmp][i]);
			}
		}
	}

	*/

	/*
	int tmp;
	b.push(v);
	chkb[v] = 1;
	while (!b.empty()) {
		tmp = b.front();
		for (int i = 0; i < d[tmp].size(); i++) {
			if (!chkb[d[tmp][i]] && d[tmp][i]!=0) {
				b.push(d[tmp][i]);
				chkb[d[tmp][i]] = 1;
			}
		}
		cout << tmp<<' ';
		b.pop();

	}
	*//*
}
int main() {
	cin >> N >> M >> V;
	int a1, a2;
	for (int i = 0; i < M; i++) {
		cin >> a1 >> a2;
		d[a1].push_back(a2);
		d[a2].push_back(a1);
	}
	for (int i = 1; i <= N; i++)
		sort(d[i].begin(), d[i].end());
	chkd.clear();
	dfs(V);
	printf("\n");
	chkb.clear();
	bfs(V);
	return 0;
}
*/
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int>> d(1001);
queue<int> q;
vector<int>chk;
void dfs(int v) {
	chk[v] = 1;
	printf("%d ", v);
	for (int i = 0; i < d[v].size(); i++) {
		if (!chk[d[v][i]]) {
			dfs(d[v][i]);
		}
	}
}
void bfs(int v) {
	q.push(v);
	chk[v] = 1;
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		printf("%d ", s);
		for (int i = 0; i < d[s].size(); i++) {
			if (chk[d[s][i]]) {
				continue;
			}
			q.push(d[s][i]);
			chk[d[s][i]] = 1;
		}
	}
}
int main() {
	int n, m, V, a, b;
	cin >> n >> m >> V;
	chk = vector<int>(n+1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	for (int j = 1; j <= n; j++) {
		sort(d[j].begin(), d[j].end());
	}
	dfs(V);
	chk = vector<int>(n + 1);
	printf("\n");
	bfs(V);
	return 0;
}