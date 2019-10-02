#include<iostream>
#include<vector>

using namespace std;
vector<int> arr;
vector<int> chk;
void dfs(int n) {
	if (!chk[n]) {
		chk[n] = 1;
		dfs(arr[n]);
	}
}
int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int cnt = 0;
		cin >> N;
		arr = vector<int>(N + 1,0);
		chk = vector<int>(N + 1,0);
		for (int i = 1; i <=N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= N; i++) {
			if(!chk[i]){
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}