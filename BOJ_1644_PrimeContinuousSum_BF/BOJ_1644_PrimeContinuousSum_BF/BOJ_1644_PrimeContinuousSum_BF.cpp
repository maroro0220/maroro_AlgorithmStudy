#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> pri;
const int MAX = 4000000;

void Prime(int n) {
	pri[0] = 0; pri[1] = 0;
	for (int i = 2; i <= n; i++) {
		pri[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (!pri[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			pri[j] = 0;
		}
	}
}
int main() {
	int N;
	cin >> N;
	pri = vector<int>(MAX+1);
	Prime(MAX);
	vector<int>setpri;
	for (int i = 0; i < pri.size(); i++) {
		if (pri[i]) {
			setpri.push_back(pri[i]);
		//	cout << pri[i] << ' ';
		}
	}
	int tot = 0, start = 0, end = 0,cnt=0;

	tot = setpri[start]; end = start;
	while (start <= end && setpri[start]<=N && end < setpri.size()) {
		if (tot < N) {
			tot += setpri[++end];
		}
		else if (tot== N) { 
			cnt++;
			tot+=setpri[++end];
		}
		else if (tot > N) {
			tot -= setpri[start++];
		}

	}
	cout << cnt;
	return 0;
}