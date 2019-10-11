#include<iostream>
#include<vector>

using namespace std;
vector < vector < vector<int>>>chk;
vector < vector<char>> table;
int N, M, K;
string word;
int cnt;
int dfs(int r, int c,int idx) {
	if(chk[r][c][idx]!=-1){
		return chk[r][c][idx];
	}
	if (word.size()-1 <= idx) {
		return 1;
	}
	chk[r][c][idx] = 0;
	for (int k = 1; k <= K; k++) {
		if ( r + k < N && idx + 1 < word.size()) { //down
			if (table[r + k][c] == word[idx + 1]) {
				chk[r][c][idx] = chk[r][c][idx] + dfs(r + k, c, idx + 1);
			}
		}
		if ( r - k >= 0 && idx + 1 < word.size()) { //up
			//chk[r - k][c][idx + 1]++;
			if(table[r - k][c] == word[idx + 1]){
				chk[r][c][idx]+=dfs(r - k, c, idx + 1);
			}
		}
		if ( c + k < M && idx + 1 < word.size()) {//right
			//chk[r][c + k][idx + 1]++;
			if(table[r][c + k] == word[idx + 1] ){
				chk[r][c][idx]+=dfs(r, c + k, idx + 1);
			}
		}
		if (c - k >= 0 && idx + 1 < word.size()) {//left
			//chk[r][c - k][idx + 1]++;
			if (table[r][c - k] == word[idx + 1]) {
				chk[r][c][idx] += dfs(r, c - k, idx + 1);
			}
		}
	}//end for
	return chk[r][c][idx];
}
int main() {
	cin >> N >> M >> K;
	table = vector< vector<char>>(N, vector<char>(M));
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			cin >> table[a][b];
		}
	}
	cin >> word;
	chk = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(80, -1)));
	int res=0;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			if (table[a][b] == word[0]) {
				res+=dfs(a, b,0);
		}
		}
	}
	cout << res;
	return 0;
}