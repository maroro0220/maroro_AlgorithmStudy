
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		int cnt;
		cin >> n >> m;
		vector<int> space(n+1);
		vector<int> car(m);
		vector<int>chk(n+1, 0); //chk space
		queue<int>q;
		for (int i = 0; i < n; i++) {
			cin >> space[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> car[i];
		}
		int tmp;
		int res = 0;
		cnt = 0;
		while (cnt < m) {
			
			cin >> tmp;
			if (tmp > 0) {
				for (int i = 0; i <= n; i++) {
					if (i == n) {
						q.push(tmp);
					}
					else if (!chk[i]) {
						res += car[tmp - 1] * space[i];
						chk[i] = tmp;
						break;
					}
					
				}
			} 
			else {
				tmp *= -1;
				for (int i = 0; i < n; i++) {
					if (chk[i] == tmp) {
						chk[i] = 0;
						cnt++;
						if (!q.empty()) {
							chk[i] = q.front();
							res += car[q.front() - 1] * space[i];
							q.pop();
						}	
						break;
					}
				}

			}
		}
		cout <<'#'<<test_case<<' '<< res << endl;




	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}