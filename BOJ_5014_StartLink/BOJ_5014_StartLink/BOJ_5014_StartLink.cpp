#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int F, S, G, U, D,cnt;
vector<int> chk;
void bfs() {
	queue<int>q;
	q.push(S);
	while (!q.empty()) {
		int size = q.size();
		chk[S] = 1;
		for (int a = 0; a < size; a++) {
			int cur = q.front(); q.pop();
			if (cur == G) { 
				cout << cnt;
				return ; 
			}
			//if (chk[cur]) continue;
			if (cur+U<=F &&!chk[cur + U]) {
				chk[cur + U]=1;
				q.push(cur + U);
			}
			 if (cur-D>0&&!chk[cur - D]) {
					chk[cur - D] = 1;
					q.push(cur - D);				
			}
		}
		cnt++;
	}
	cout << "use the stairs";
}
int main() {

	cin >> F >> S >> G >> U >> D;
	chk = vector<int>(F+1, 0);
	bfs();
	return 0;
}