#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;
vector<int> chk;
struct DSLR {
	int cur;
	//vector<int> cal;//0=start 1=D 2=S 3=L 4=R
	string cal;
};
void bfs(int S,int D) {
	queue<DSLR> q;
	DSLR tmp;
	chk = vector<int>(10000, 0);
	tmp.cur = S;
	//tmp.cal=' ';
	q.push(tmp);
	while (!q.empty()) {
		int size = q.size();
		for (int a = 0; a < size; a++) {
		DSLR c = q.front(); q.pop();
		if (c.cur == D) { 
			cout << c.cal<<endl;
			return; 
		}

		for (int i = 1; i <= 4; i++) {
				DSLR itmp;
				if (i == 1) {//D
					itmp.cur =( c.cur * 2)%10000;
						//if (itmp.cur > 9999) itmp.cur %= 10000;
						
					if (!chk[itmp.cur]) {
						chk[itmp.cur] = 1;
						//itmp.cal=c.cal.push_back(i);
						itmp.cal = c.cal + 'D';
						q.push(itmp);
					}
				}
				else if (i == 2) {//S
					itmp.cur = c.cur - 1;
						if (itmp.cur < 0) itmp.cur = 9999;
					if (!chk[itmp.cur]) {
						chk[itmp.cur] = 1;
						//itmp.cal.push_back(i);
						itmp.cal = c.cal + 'S';
						q.push(itmp);
					}
				}
				else if (i == 3) {//L
					itmp.cur = c.cur;
					/*
						string str = to_string(itmp.cur);
						char tmpstr;
						if (str.length() > 1) {
						tmpstr = str[0];
							for (int i = 0; i < str.length() - 1; i++) {
								str[i] = str[i + 1];
							}
							str[3] = tmpstr;
						}
						itmp.cur = atoi(str.c_str());
						*/
					itmp.cur = (c.cur % 1000) * 10 + c.cur / 1000;
					if (!chk[itmp.cur]) {
						chk[itmp.cur] = 1;
						//itmp.cal.push_back(i);
						itmp.cal = c.cal + 'L';
						q.push(itmp);
					}
				}
				else if (i == 4) {//R
					itmp.cur = c.cur;
					/*
						string str = to_string(itmp.cur);
						char tmpstr3, tmpstr;
						if (str.length() > 1) {
							tmpstr3 = str[3];
							for (int i = str.length() - 2; i >= 0; i--) {
								tmpstr = str[i];
								str[i + 1] = str[i];
							}
							str[0] = tmpstr3;
						}
						itmp.cur = atoi(str.c_str());
						*/
					itmp.cur = (c.cur % 10) * 1000 + (c.cur / 10);
						//itmp.cal.push_back(i);
					if (!chk[itmp.cur]) {
						chk[itmp.cur] = 1;
						itmp.cal = c.cal + 'R';
						q.push(itmp);
					}
				}
			}//end for i
		}//end for a

	}//end q while
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		bfs(a, b);

	}
}