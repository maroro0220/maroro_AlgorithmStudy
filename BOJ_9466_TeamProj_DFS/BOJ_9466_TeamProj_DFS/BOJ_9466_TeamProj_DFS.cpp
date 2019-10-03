#include<iostream>
#include<vector>
using namespace std;
vector<int> stud;
vector<int> chk;
int start;
bool dfs(int n) {
	if (n == start) {

		return true;
	}
	if (!chk[n]) {
		chk[n] = 1;
		if (dfs(stud[n])) {
			return true;
		}
		else
			chk[n] = 0;
	}
	//chk[n] = 0;
	return false;

}
int main() {
	int T, n;
	cin >> T;
	for (int t = 0; t < T; t++) {//Test case Num
		cin >> n;
		chk = vector<int>(n + 1, 0);
		stud = vector<int>(n + 1, 0);
		for (int j = 1; j <=n;j++) {
			cin >> stud[j];
		}
		for (int i = 1; i <= n; i++) {
			
			if (!chk[i]) {
				start = i;
				chk[i] = 1;
				if (dfs(stud[i])) {
					//continue;
				}
				else chk[i] = 2;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i]==2) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}