#include <iostream>
#include<vector>
using namespace std;
vector<int>arr[100001];
vector<int>chk;
int n, s, d;
bool res;
bool resd;
void dfs(int start, int dest, int stopover,bool re) {

	if (start == dest) {
		if (re == true) { 
			resd = true; 
		}
		return;
	}
	chk[start] = 1;
	for (int i = 0; i < arr[start].size(); i++) {
		if (chk[arr[start][i]] == 1)continue;
		chk[arr[start][i]] = 1;
		if (arr[start][i] == stopover) re = true;
		dfs(arr[start][i], dest, stopover,re);
		chk[arr[start][i]] = 0;
		if (resd)return;
	}
		res = false;

}
int main() {
	int a, b, m;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int st, des, sto;
		chk = vector<int>(n + 1, 0);
		res = false;
		resd = false;
		cin >> st >> des >> sto;
		dfs(st, des, sto,false);
		if (resd) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}