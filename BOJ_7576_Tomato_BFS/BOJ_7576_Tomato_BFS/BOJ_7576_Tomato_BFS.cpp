#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Posi
{
	int r, c;
};

vector<vector<int>>warehouse;
vector<Posi>wellto;
queue<Posi> q;
int M, N,cnt;
void chk(int r, int c) {
	if (!warehouse[r][c]);
}
void bfs() {
	int size = wellto.size();
		for (int i = 0; i < size; i++) {
			q.push(wellto[i]);
		}
		while (!q.empty()) {
			size = q.size();
			for (int a = 0; a < size; a++) {
				Posi cur = q.front(); q.pop();
				Posi tmp;
				if (cur.r - 1 >= 0 && warehouse[(cur.r) - 1][cur.c] == 0)//r-1, c up
				{
					warehouse[(cur.r) - 1][cur.c] = 1;
					tmp.r = cur.r - 1; tmp.c = cur.c;
					q.push(tmp);
				}
				if (cur.c + 1 < M && warehouse[cur.r][cur.c + 1] == 0)//r, c+1 right
				{
					warehouse[(cur.r)][cur.c+1] = 1;
					tmp.r = cur.r; tmp.c = cur.c+1;
					q.push(tmp);
				}
				if (cur.r + 1 < N && warehouse[(cur.r) + 1][cur.c] == 0)//r+1,c down
				{
					warehouse[(cur.r) + 1][cur.c] = 1;
					tmp.r = cur.r + 1; tmp.c = cur.c;
					q.push(tmp);
				}
				if (cur.c - 1 >= 0 && warehouse[(cur.r)][(cur.c) - 1] == 0)//r, c-1 left
				{
					warehouse[(cur.r)][cur.c - 1] = 1;
					tmp.r = cur.r; tmp.c = cur.c - 1;
					q.push(tmp);
				}
			}
			cnt++;
		}//end while
}
int main() {
	cin >> M >> N;//M=col y, N=row x
	cnt = -1;
	warehouse = vector<vector<int>>(N,vector<int>(M,0));
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			cin>>warehouse[a][b]; //1=well, 0=notyet, -1=empty
			if (warehouse[a][b] == 1) {
				Posi tmp;
				tmp.r = a; tmp.c = b;
				wellto.push_back(tmp);
				//cnt = 0;
			}
		}
	}//end for a. input warehouse;
	bfs();
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			if (!warehouse[a][b]) cnt = -1;
		}
	}
	cout << cnt;
	return 0;
}