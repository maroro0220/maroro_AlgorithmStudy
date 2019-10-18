#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	int sum = 0,tot=0;
	vector<int>t(N);
	for (int i = 0; i < N; i++) {
		sum += p[i];
		tot+= sum;
	}
	cout << tot;
	return 0;
}