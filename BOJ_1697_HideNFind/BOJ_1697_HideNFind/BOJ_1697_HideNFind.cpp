#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K,Max; //N=Subin, K=sister
int cnt;
queue<int>q;
vector<int>chk;
void bfs() {
	q.push(N);
	cnt = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int tmp = q.front(); q.pop();
			if (tmp == K) return;
			if ((tmp - 1) >= 0 && (tmp - 1) <= 100000 && !chk[tmp - 1]) { 
				chk[tmp - 1] = 1;
				q.push(tmp - 1); 
			}
			if ((tmp + 1) >= 0 && (tmp + 1) <= 100000 && !chk[tmp + 1]) {
				chk[tmp + 1] = 1;
				q.push(tmp + 1);
			}
			if ((tmp * 2) >= 0 && (tmp * 2) <=100000 && !chk[tmp * 2]) {
				chk[tmp * 2] = 1;
				q.push(tmp * 2);
			}
		}
		cnt++;
	}
	

}
int main() {
	cin >> N >> K;
	Max = abs(N - K);
	chk = vector<int>(100000,0);
	bfs();
	cout << cnt;
	return 0;
}