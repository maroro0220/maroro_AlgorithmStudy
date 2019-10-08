#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

//int arr[3][3];
//int chk[3][3];
/*
struct Posi {
	int r, c,cnt;
};
Posi zero;
*/
vector<int> chk(9, 0);
//vector<int> arr(9, 0);
int zero;
int puzle;
string pstr;
int cnt;
void bfs() {
	//int dx[4] = { 0,0,-1,1 };
	//int dy[4] = { -3,3,0,0 };
	map<string, int> m;
	int d[4] = { -3,3,-1,1 };
	queue<pair<string,int>> q;
	pstr = to_string(puzle);
	//q.push(zero);
	q.push(make_pair(pstr,zero));
	m[pstr] = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int a = 0; a < size; a++) {
			pair<string, int> stmp = q.front(); q.pop();
			/*	
		Posi tmp = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				Posi t;
				if ((tmp.c + dx[i]) < 0 || (tmp.c+dx[i])>2|| (tmp.r + dy[i]) < 0 || (tmp.r + dy[i]) > 2) continue;
				t.r = tmp.r + dy[i];
				t.c = tmp.c + dx[i];
				if (!chk[t.r][t.c]) {
					int ch;
					ch = arr[t.r][t.c];
					arr[t.r][t.c] = 0;
					arr[tmp.r][tmp.c] = ch;
					chk[t.r][t.c] = 1;
					t.cnt = tmp.cnt + 1;
				}
			}
			*/
			if (!stmp.first.compare("123456780")) {
				cout << cnt;
				return;
			}
			zero = stmp.second;
			for (int i = 0; i < 4; i++) {
				pair<string, int>st=stmp;
				int tmp;
				tmp = zero + d[i];
				if (tmp < 0 || tmp>8) continue;
				//if (chk[tmp] == 1) continue;
				//chk[tmp] = 1;
				swap(st.first[tmp], st.first[zero]);
				if (m.count(st.first)) continue;
				st.second = tmp;
				q.push(st);
			}

		}//end for
		cnt++;
	}//end while
	cnt = -1;
}//end bfs()
int main() {
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		if (!tmp) zero = i;
		puzle = puzle * 10+tmp;
	}
	bfs();
	return 0;
}