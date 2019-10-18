#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int V,maxi,fnode;
vector<pair<int,int>> tree[100001];
vector<int>chk;

void dfs(int idx,int sum) {
	//if (chk[idx]) return;
	//chk[idx] = 1;
	if (maxi < sum) {
		maxi = sum;
		fnode = idx;
	}
	for (int i = 0; i < tree[idx].size(); i++) {
		int next_idx = tree[idx][i].first;
		if (!chk[next_idx]) {
			sum += tree[idx][i].second;
			chk[next_idx] = 1;
			dfs(next_idx,sum);
			//maxi = max(maxi, sum);
			sum -= tree[idx][i].second;
			//chk[next_idx] = 0;
		}
	}
	//sum = 0;
	
}

int main() {
	cin >> V;
	chk = vector<int>(V+1, 0);
	int tmp = V;
	while (tmp--) {
		int i;
		cin >> i;
		int a=0, b;
		while(a!=-1){
			cin >> a;
			if (a == -1) {
				break;
			}
			cin >> b;
			tree[i].push_back({ a,b });
		}
	}

		dfs(1, 0);
		chk = vector<int>(V+1);
		maxi = 0;
		chk[fnode] = 1;
		dfs(fnode, 0);
	cout << maxi;
	return 0;
}