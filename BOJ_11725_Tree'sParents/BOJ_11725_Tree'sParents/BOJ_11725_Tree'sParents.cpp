#include<iostream>
#include<vector>

using namespace std;

int N;
//vector<vector<int>> tree;
vector<int>tree[100001];
//vector<int>chk, par;
int par[100001];
bool chk[100001];
void dfs(int idx) {
		chk[idx] = true;
		for (int i = 0; i < tree[idx].size(); i++) {
		//if (idx == i) continue;
			int next = tree[idx][i];
		if (!chk[next]) {
			par[next] = idx;
			//tree[i][idx] = 0;
			dfs(next);
		}
	}
}
int main() {
	cin >> N;
	//tree = vector<vector<int>>(N+1, vector<int>(N+1, 0));
//	par = vector<int>(N+1, 0);
//	chk = vector<int>(N+1, 0);
	int a, b;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
//		tree[a][b] = 1;
//		tree[b][a] = 1;
	}
dfs(1);
	for (int i = 2; i <= N;i++) {
		//cout << par[i]<<"\n";
		printf("%d\n", par[i]);
	}
	return 0;
}