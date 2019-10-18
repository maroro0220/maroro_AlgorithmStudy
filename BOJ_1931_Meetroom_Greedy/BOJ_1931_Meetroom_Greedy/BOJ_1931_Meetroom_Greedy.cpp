#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//vector<int> meet[100001];
vector<int> b, e;
int  N;
int main() {
	int cnt=1;
	cin >> N;
	b = e = vector<int>(N);
	vector<pair<int, int>>ord;
	for (int i = 0; i < N; i++) {
		cin >> b[i] >> e[i];
		ord.push_back({ e[i],b[i] });
	}
	sort(ord.begin(), ord.end());
	int last=ord[0].first;
	for (int i = 1; i < ord.size(); i++) {
		if (ord[i].second >= last) {
			last = ord[i].first;
			++cnt;
		}
	}
	cout << cnt;
		
	return 0;
}