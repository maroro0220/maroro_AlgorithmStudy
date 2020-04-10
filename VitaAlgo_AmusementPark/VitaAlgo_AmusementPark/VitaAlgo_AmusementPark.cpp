
#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[16][16];
int d[1 << 16][16];
int chk[17];
int n;
int sum;
int start;
int mini = 100000000;
/*
void dfs(int idx,int cnt) {
	if (cnt >= n && idx==start) {
		if (mini > sum) mini = sum;
		return ;
	}
	if (chk[idx])return;
	//chk[idx] = 1;
	for (int i = 0; i < n; i++) {
		if ( arr[idx][i] == 0)continue;
		chk[idx] = 1;
		sum += arr[idx][i];
		if (sum <= mini) {
			dfs(i, cnt + 1);
		}
		sum -= arr[idx][i];
		chk[idx] = 0;
	}
}
*/
int dfs(int cur,int st) {
	if (st == (1 << n) - 1) {
		return arr[cur][0] ? arr[cur][0] : 1000000000;
	}
	int& res = d[st][cur];
	if (res != -1)return res;
	res = 1000000000;
	for (int i = 0; i < n; i++) {
		if ((st & (1 << i)) == 0 && arr[cur][i]) {
			res = min(res, dfs(i, st | (1 << i))+arr[cur][i]);
		}
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	sum = 0;
	//for (int i = 0; i < n; i++) {
	mini = dfs(0, 1);
		//start =0;
		//dfs(0,0);
	//}
	//cout << mini;
	printf("%d", mini);
	return 0;
}