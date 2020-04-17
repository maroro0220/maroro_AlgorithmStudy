#include <iostream>
#include<vector>
using namespace std;
vector<int> grap[100001];
int ac[100001];
//vector<int>dep;
int* dep;
//int n;
void dfs(int now, int parent) {
	dep[now] = dep[parent] + 1;
	ac[now] = parent;
	for (int i = 0; i < grap[now].size(); i++) {
		if (grap[now][i] == parent) continue;
		dfs(grap[now][i], now);
	}
}
int main() {
	int a, b,m,n;
	cin >> n;
	//dep = vector<int>(n + 1, 0);
	dep = new int[n + 1]();
	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		grap[a].push_back(b);
		grap[b].push_back(a);
	}
	dfs(1, 0);
	cin >> m;
	while(m--) {
		cin >> a >> b;
		if (dep[a] != dep[b]) {
			if (dep[a] > dep[b]) swap(a, b);
			while (dep[a]<dep[b])
			{
				b = ac[b];
			}
		}
		int res;
		while (true) {
			if (a == b) {
				res = a;
				break;
			}
			a = ac[a];
			b = ac[b];
		}
		printf("%d\n", res);
	}
	return 0;
}