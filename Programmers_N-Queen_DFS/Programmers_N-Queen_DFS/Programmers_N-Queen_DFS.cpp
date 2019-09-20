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
/*
//https://wkdtjsgur100.github.io/N-Queen/
#include <iostream>

using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i)
{
	for(int j=0;j<i;j++)
	{
		// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
		if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
			return false;
	}
	return true;
}
void N_Queen(int i)
{
	if(i == N)
		result += 1;
	else
	{
		for(int j=0;j<N;j++)
		{
			col[i] = j;
			if(promising(i))
				N_Queen(i+1);
		}
	}
}

int main()
{
	cin>>N;

	N_Queen(0);

	cout<<result<<endl;

	return 0;
}
*/