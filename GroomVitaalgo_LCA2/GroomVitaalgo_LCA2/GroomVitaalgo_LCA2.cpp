#include <iostream>
#include<vector>
using namespace std;
vector<int> grap[100001];
int* ac;
//vector<int>dep;
int* dep;
//int n;
void dfs(int now, int parent) {
	dep[now] = dep[parent] + 1;
	ac[now] = parent;
	for (int i = 0; i < grap[now].size(); i++) {
		if (grap[now][i] == parent||dep[grap[now][i]]) continue;
		dfs(grap[now][i], now);
	}
}
int main() {
	int a, b,m,n;
	scanf("%d", &n);
	//dep = vector<int>(n + 1, 0);
	ac = new int[n + 1]();
	dep = new int[n + 1]();
	for(int i=0;i<n-1;i++){
		scanf("%d %d", &a, &b);
		grap[a].push_back(b);
		grap[b].push_back(a);
	}
	dep[0] = -1;
	dfs(1, 0);
	scanf("%d", &m);
	while(m--) {
		int res;
		scanf("%d %d", &a, &b);
		if (a == 1 || b == 1) {
			printf("1\n"); 
			continue;
		}
		if (dep[a] != dep[b]) {
			if (dep[a] > dep[b]) swap(a, b);
			while (dep[a]<dep[b])
			{
				b = ac[b];
			}
		}
		res = a;

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