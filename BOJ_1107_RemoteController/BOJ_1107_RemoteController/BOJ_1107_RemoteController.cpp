#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr;
vector<int> ch(10, 1); //Button. If button work=1.
int Chk(int b) {
	int cnt = 0;
	while (1) {
		if (b == 0) {
			if (ch[b] == 0) {
				return 0;
			}
			else return 1;
		}
		cnt++;
		if (ch[b % 10] == 0) {
			return 0;
		}
		b /= 10;
		if (b == 0) {
			return cnt;
		}
	}
}
int main() {
	int N,M,tmp;
	cin >> N;
	cin >> M;

	int Min = abs(N - 100);

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		ch[tmp] = 0;
	}/*
	if (N==0 && Chk(0)) {
			cout << 1;
			return 0;
	}
	*/
	if (!Min) {
		cout << 0;
		return 0;
	}
	int len;
	for (int i = 0; i <=1000000; i++) {
		len = Chk(i);
		if (len) {
			Min = min(Min, abs(i - N)+len);
		}
	}
	cout << Min;
	/*
	int idx = 0, cnt = 0;
	while (idx<arr.size()) {
		for (int i = 0; i <= 9; i++) {
			int Min = 10;
			if (ch[i]) {
				if (arr[idx] == i) {
					break;
				}
				else {
					if(abs(idx-i)==9)
					arr[idx]=min(Min, abs(idx - i));

				}
			}
		}
		cnt++;
	}
	*/
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
	return 0;
}