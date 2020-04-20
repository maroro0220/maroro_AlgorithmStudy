#include <iostream>
#include<vector>
using namespace std;
int n;
//vector<vector<int>> arr;
vector<int>arr[100001];
int family[100001][17];
int dep[100001];
//vector<int>chk;
void DFS(int now, int parent) {
	dep[now] = dep[parent] + 1;
	family[now][0] = now;
	family[now][1] = parent;
	for (int i = 2; i < 17; i++) {
		family[now][i] = family[family[now][i - 1]][i - 1];
		if (family[now][i] == 1) break;
	}
	int siz = arr[now].size();
	for (int i = 0; i < siz; i++) {
		if (arr[now][i] == parent) continue;
		DFS(arr[now][i], now);
	}
}
int main() {
	cin >> n;
	//arr = vector<vector<int>>(n + 1, vector<int>(n+1,0));
	//chk = vector<int>(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		//arr[a][b] = 1;
		//arr[b][a] = 1;
	}
	DFS(1, 0);
	int node1, node2;
	cin >> node1 >> node2;
	if (dep[node1] != dep[node2]) {
		if (dep[node1] > dep[node2]) {
			swap(node1, node2);
		}
		while (dep[node1] < dep[node2]) {
			node2 = family[node2][1];
		}
	}
	int res;
	while (true) {
		if (node1 == node2) {
			res = node1;
			break;
		}
		node1 = family[node1][1];;
		node2 = family[node2][1];;
	}
	printf("%d", res);
	return 0;
}
/*
#include <iostream>
#include<vector>
using namespace std;
int n;
//vector<vector<int>> arr;
vector<int>arr[100001];
int family[100001][17];
int dep[100001];
//vector<int>chk;
void DFS(int now,int parent) {
	dep[now] = dep[parent] + 1;
	family[now][0] = now;
	family[now][1] = parent;
	for (int i = 2; i < 17; i++) {
		family[now][i] = family[family[now][i - 1]][i - 1];
		if (family[now][i] == 1) break;
	}
	int siz = arr[now].size();
	for (int i = 0; i < siz; i++) {
		if (arr[now][i] == parent) continue;
		DFS(arr[now][i], now);
	}
}
int main() {
	cin >> n;
	//arr = vector<vector<int>>(n + 1, vector<int>(n+1,0));
	//chk = vector<int>(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		//arr[a][b] = 1;
		//arr[b][a] = 1;
	}
	DFS(1, 0);
	int node1, node2;
	cin >> node1 >> node2;
	if (dep[node1] != dep[node2]) {
		if (dep[node1] > dep[node2]) {
			swap(node1, node2);
		}
		while (dep[node1] < dep[node2]) {
			node2 = family[node2][1];
		}
	}
	int res;
	while (true) {
		if (node1 == node2) {
			res = node1;
			break;
		}
		node1 = family[node1][1];;
		node2 = family[node2][1];;
	}
	printf("%d", res);
	return 0;
}
*/