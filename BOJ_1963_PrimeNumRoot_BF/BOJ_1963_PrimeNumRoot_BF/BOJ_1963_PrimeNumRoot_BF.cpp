#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
vector<int> prime(2);
vector<int>num,resP,chk;
int cnt;
void Prime() {
num = vector<int>(10000, 1);
		for (int i = 2; i <= sqrt(9999); i++) {
			if (num[i] == 0) continue;
			for (int j = i * 2; j <= 9999; j += i) {
				num[j] = 0;
			}
		}
		/*
		for (int a = 1000; a <10000; a++) {
			if (num[a] == 1) {
				resP.push_back(num[a]);
				//cout << a<<' ';
			}
		}
		*/
		//cout << endl;
}
void bfs() {
	queue<int> q;
	chk = vector<int>(10000, 0);
	q.push(prime[0]);
		while (!q.empty()) {
			int s = q.size();
			for (int i = 0; i <s; ++i) { //if i<q.size(), there is a error. Bcuz q size is changed every term. q.push()
				
				int cur = q.front(); q.pop();
				//if (chk[cur]==1) continue;
				chk[cur] = 1;

				if (cur == prime[1]) { 
					return; 
				}
				string str1 = to_string(cur);
				for (int a = 0; a < 4; ++a) {
					string tmp = string(str1);
					for (int b = 0; b < 10; ++b) {
						tmp[a] = b+48 ;
						int inte = stoi(tmp);
						//if (chk[inte] == 1)continue;
						if (num[inte] && inte>=1000 && !chk[inte]) {
							chk[inte] = 1;
							q.push(inte);
						}
					}
				}
			}
			cnt++;
		}
		cout << "Impossible" << endl;
		return;
}
int main() {
	int T;
	cin >> T;
	Prime();
	for (int t = 0; t < T; t++) {
		cin >> prime[0] >> prime[1];
		cnt = 0;
		bfs();
		cout << cnt<<endl;
	}//end for test case

	return 0;
}