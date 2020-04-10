#include <iostream>
using namespace std;
int arr[17][17];
int chk[17];
int n;
int sum;
int start;
int mini = 100000000;
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
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	sum = 0;
	//for (int i = 0; i < n; i++) {
		
		start =0;
		dfs(0,0);
	//}
	cout << mini;
	return 0;
}