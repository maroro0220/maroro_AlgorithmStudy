#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int zero;
int puzle;

int cnt;
void bfs() {
	string pstr;	
	map<string, int> m;
	int d[4] = { -3,3,-1,1 };
	queue<string> q;
	pstr = to_string(puzle);
	q.push(pstr);
	m[pstr] = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int a = 0; a < size; a++) {
			string stmp = q.front(); q.pop();
			if (stmp == "123456780"){
				cout << cnt;
				return;
			}				
			string st;
			zero = stmp.find('0');
			for (int i = 0; i < 4; i++) {
				if (((zero % 3 == 2) && i == 3) || ((zero % 3 == 0) && i==2)) { 
					continue; }

				int tmp;
				tmp = zero + d[i];
				if (tmp < 0 || tmp>8) continue;
				
				else {st = stmp;
					swap(st[tmp], st[zero]);
					if (m.count(st)) {
					continue;
					}
					m[st] = 1;

					q.push(st);
				}
			}

		}//end for
		cnt++;
	}//end while
	cnt = -1;
	cout<< cnt;
	return;
}//end bfs()
int main() {
	int tmp;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		puzle = puzle * 10+tmp;
	}
	bfs();
	return 0;
}