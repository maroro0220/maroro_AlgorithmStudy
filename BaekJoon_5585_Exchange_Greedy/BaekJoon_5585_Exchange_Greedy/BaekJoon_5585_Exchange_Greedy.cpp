#include<vector>
#include<iostream>
using namespace std;

int main() {
	int n;
	vector<int>m = { 500,100,50,10,5,1 };
	cin >> n;
	n = 1000 - n;
	int cnt = 0;
	for (int i = 0; i < m.size(); i++) {
		while (n-m[i]>=0) {
			n -= m[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}