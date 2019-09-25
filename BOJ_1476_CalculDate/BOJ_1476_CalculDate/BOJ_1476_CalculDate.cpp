#include<vector>
#include<iostream>
using namespace std;

int main() {
	vector<int> cal(3,0),d(3,0);
	int cnt=0;
	cin >> cal[0] >> cal[1] >> cal[2];
	while (1) {
		if (cal[0] == d[0] && cal[1] == d[1] && cal[2] == d[2]) {
			break;
		}
		cnt++;
		if (d[0] < 15) {
			d[0]++;
		}
		else if (d[0] >= 15) {
			d[0] = 1;
		}
		if (d[1] < 28) {
			d[1]++;
		}
		else if (d[1] >= 28) {
			d[1] = 1;
		}
		if (d[2] < 19) {
			d[2]++;
		}
		else if (d[2] >= 19) {
			d[2] = 1;
		}
	}
	printf("%d", cnt);
	return 0;
}