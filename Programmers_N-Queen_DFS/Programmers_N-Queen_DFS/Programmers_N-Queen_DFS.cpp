#include <string>
#include <vector>

using namespace std;
vector<vector<int>> b;
int nn;
int cnt;
bool Chk(int aa, int bb) {
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (aa == i || bb == j) {
				if (b[i][j]) {
					return false;
				}
			}
			else if (abs(aa - i) == abs(bb - j)) {
				if (b[i][j]) {
					return false;
				}
			}
		}
	}
	return true;
}
void dfs(int a) {
	if (a == nn) {
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < nn; j++) {
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}printf("\n");
		cnt++;
	}
	for (int i = 0; i < nn; i++) {
		if(Chk(a, i)){
			b[a][i] = 1;
			dfs(a + 1);
			b[a][i] = 0;
		}
	}
}
int solution(int n) {
	int answer = 0;
	nn = n;
	vector < vector<int>> board(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}
	b = board;
	dfs(0);
	
	answer = cnt;
	printf("%d", cnt);
	return answer;
}

int main() {
	solution(4);
	return 1;
}