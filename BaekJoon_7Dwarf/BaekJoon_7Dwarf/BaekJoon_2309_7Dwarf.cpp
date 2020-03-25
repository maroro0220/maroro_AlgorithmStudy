#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>heights(9);
vector<int>chk(9);
vector<int>dwarf(7);
bool Find(int h, int cnt) {
	if (cnt == 7) {
		int sum = 0;
		for (int i = 0; i < cnt; i++) {
			sum += dwarf[i];
		}
		if (sum == 100) {
			sort(dwarf.begin(),dwarf.end());
			for (int i = 0; i < 7; i++) {
				cout << dwarf[i]<<'\n';
			}
			return true;
		}
		return false;
	}
	if (cnt>7||h >= 9) return false;
	for (int k = h; k < 9; k++) {
		if (chk[k])continue;
		chk[k] = 1;
		dwarf[cnt] = heights[k];
		if (Find(k, cnt + 1)) {
			return true;
		}
		chk[k]=0;
	}
	return false;
}
int main() {
	for (int i = 0; i < 9; i++) {
		cin >> heights[i];
	}
	for (int i = 0; i < 9; i++) {
		if (Find(i,0))break;
	}

	return 0;
}