#include<vector>
#include<iostream>
using namespace std;
int N, M, cnt;
vector<int> arr[10001];
vector<int> chk(1001, 0);
void dfs(int c) {
	
	
	if(chk[c] == 0) {
		for (int i = 0; i < arr[c].size(); i++) {
			chk[c] = 1;
			dfs(arr[c][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	int tmp1, tmp2;
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		arr[tmp1].push_back(tmp2);
		arr[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= N; i++) {
		if(chk[i]==0){
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}