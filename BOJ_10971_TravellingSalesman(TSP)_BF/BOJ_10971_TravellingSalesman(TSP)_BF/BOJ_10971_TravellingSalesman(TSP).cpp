#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,start;
vector<vector<int>>city;
vector<int>chk;
int MinRoot = 10000000;
void dfs(int strt, int r,int cnt,int sum) {
	if (cnt == N && strt == r) {
		if (MinRoot > sum) MinRoot = sum;
		//return MinRoot;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (city[r][i]==0) continue;
		if (city[r][i]>0 && !chk[r])
		{
			chk[r] = 1;
			sum += city[r][i];
			if(sum<=MinRoot)
				dfs(strt, i, cnt + 1,sum);
			chk[r] = 0;
			sum -= city[r][i];
		}

	}
}
/*
int dfs(int r,int c,int cnt) {
		int ret;
	if(cnt==N-1){
		if (city[r][start]) {
			ret = sum+city[r][start];
			//sum = 0;
			//cnt = 0;
			return ret;
		}
	}
	//if (city[r][c]>0){
		//chk[r] = 1;
		for (int i = 0; i < N; i++) {
			if (chk[i]==0 &&city[r][i]>0) {
				chk[i] = 1;
				sum += city[r][i];
				dfs(i, 0, cnt + 1);
				chk[i] = 0;
			}
		}
		//chk[r] = 0;
	//}

}
*/
int main() {
	cin >> N;
	city = vector<vector<int>>(N, vector<int>(N));
	chk = vector<int>(N,0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
		}
	}//end for enter map

	
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j ||chk[i]||chk[j]) continue;
			else {
				//chk[i] = 1;
				start = i;
				//chk[j] = 1;
				MinRoot=min(dfs(i,j,0),MinRoot);
				//chk.clear();
				//chk[i] = 0;
				//chk[j] = 0;
			}
		}
	}*/	
	for (int i = 0; i < N; i++) {

		dfs(i, i, 0,0);
		//MinRoot = min(tmp, MinRoot);
		
		//if (city[i][0] > 0) {
		/*
			start = i;
			chk[i] = 1;

			int tmp = dfs(i, 0, 0);
			MinRoot=min(tmp,MinRoot);
			chk[i] = 0;
			sum = 0;
			*/

		//}
	}
	cout << MinRoot;
	return 0;
}