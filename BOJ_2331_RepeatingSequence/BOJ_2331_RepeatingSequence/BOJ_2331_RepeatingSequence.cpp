#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int>D;
vector<int>tmp;
int chk[30000];
int A,P;

void Div(int n) {
	tmp.clear();
	while (n > 0) {
		tmp.push_back(n % 10);
		n /= 10;
	}
	reverse(tmp.begin(), tmp.end());
}
int Po() {
	int sum = 0;
	for (int i = 0; i < tmp.size(); i++) {
		sum += pow(tmp[i], P);
	}
	return sum;
}
void Dfs(int n) {
	int tmp;
	if (chk[n] == 2) {
		return;
	}
	chk[n]++;
	Div(n);
	tmp = Po();
	//chk[tmp]++;
	Dfs(tmp);
}
int main() {
	//D.push_back(0);
	cin >> A>>P;
	//D.push_back(A);
	Dfs(A);
	int cnt = 0;
	for (int i = 0;i<30001 ; i++) {
		if (chk[i] == 1)
			cnt++;

	}
	cout << cnt;
	//pow(, P);
	return 0;
}