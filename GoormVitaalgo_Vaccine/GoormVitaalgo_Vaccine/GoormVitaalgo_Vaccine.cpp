#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>pp[200001];
vector<int> chk;
queue<int> pq;
int dfs(int idx) {
	if (chk[idx]) return 0;
	chk[idx] = 1;
	int res=1;	
	for (int i = 0; i < pp[idx].size(); i++) {
		res += dfs(pp[idx][i]);
		
	}
	return res;
}
int bfs(int idx) {
	chk[idx] = 1;
	int cnt = 0;
	pq.push(idx);
	while (pq.size()) {
		int cur = pq.front();
		pq.pop();
		cnt++;
		for (int i = 0; i < pp[cur].size(); i++) {
			if (chk[pp[cur][i]]) continue;
			chk[pp[cur][i]]=1;
			pq.push(pp[cur][i]);
		}
	}
	return cnt;
}

int main() {
	int n, m;// num of people, num of relationship
	cin >> n >> m;
	chk = vector<int>(n+1, 0);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pp[a].push_back(b);
		pp[b].push_back(a);
	}
	int max = 0,maxi;
	for (int i = 1; i <= n; i++) {
		if (pp[i].empty()) continue;
		else {
			int ret;
			//ret=dfs(i);
			ret = bfs(i);
			if (ret > max) {
				max = ret;
				maxi = i;
			}
		}
	}
	cout << maxi << ' ' << max;
	

	return 0;
}