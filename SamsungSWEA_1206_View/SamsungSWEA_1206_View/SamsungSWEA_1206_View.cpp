#include<iostream>
#include<vector>
#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;
vector<int>h;
int cnt;
int chk(int a) {
	int mm,m, r, l,c=0;
	m = 256; mm = 0;
	for (int i = 1; i <= 2; i++) {
		if (a == 2) {
			r = h[a] - h[a + i];
			l = 256;
		}
		else if (a == h.size() - 2) {
			r = 256;
			l = h[a] - h[a - i];
		}
		else {
			r = h[a] - h[a + i];
			l = h[a] - h[a - i];
		}
		if (r > 0 && l > 0) {
			mm = MIN(r, l);
			m = MIN(m, mm);
			c = 1;
		}
		else {
			c = 0;
			break;
		}
	}
	if (c) {
		cnt += m;
		return m;
	}
	return 0;
}
int main() {
	int T = 10;
	int num, flag = 0;
	//vector<int>h;
	for (int t = 1; t <= T; t++) {
		cnt = 0;
		cin >> num;
		//scanf("%d", &num);
		h = vector<int>(num);
		for (int i = 0; i < num; i++) {
			cin >> h[i];
		}
		for (int i = 2; i < num - 2; i++) {
			flag = chk(i);
			if (flag) {
				i += 2;
			}
		}
		printf("#%d %d\n", t, cnt);
	}
	return 0;
}