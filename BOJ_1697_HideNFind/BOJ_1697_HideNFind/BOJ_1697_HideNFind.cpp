#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K,Max; //N=Subin, K=sister
int cnt;
queue<int>q;
vector<int>chk;
/*
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
	

}*/
struct qu{
	int posi, cnt;
};
queue<qu>quu;
qu tmp;
void bfs() {
	//queue<pair<int, int>> q;
	//q.push(pair<int,int>(N,0));

	tmp.posi = N;
	tmp.cnt = 0;
	quu.push(tmp);
	while (!quu.empty()) {
		tmp = quu.front(); quu.pop();
		if (tmp.posi == K) return;
		if (!chk[tmp.posi - 1] && (tmp.posi - 1) >= 0 && (tmp.posi - 1) <= 100000) {
			chk[tmp.posi - 1] = 1;
			qu tmp1 = tmp;
			tmp1.posi--;
			tmp1.cnt++;
			quu.push(tmp1);
		}
		if (!chk[tmp.posi + 1] && (tmp.posi + 1) >= 0 && (tmp.posi + 1) <= 100000) {
			chk[tmp.posi + 1] = 1;
			qu tmp2 = tmp;
			tmp2.posi++;
			tmp2.cnt++;
			quu.push(tmp2);
		}
		if (!chk[tmp.posi *2] && (tmp.posi*2) >= 0 && (tmp.posi *2) <= 100000) {
			chk[tmp.posi*2] = 1;
			qu tmp3 = tmp;
			tmp3.posi*=2;
			tmp3.cnt++;
			quu.push(tmp3);
		}
	}

}
int main() {
	cin >> N >> K;
	Max = abs(N - K);
	chk = vector<int>(100000,0);
	bfs();
	//cout << cnt;
	cout << tmp.cnt;
	return 0;
}