#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int L, C;
vector<string> res;
vector<string> arr;
vector<char> pw;
vector<int> com;
int vocnt;
bool Check(string st) {
	int cntv=0;
	for (int i = 0; i < L; i++) {
		if (st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') {
			cntv++;
			//cout << st[i] << endl;
		}
	}
	if (cntv > 0 && (L - cntv) > 1) return true;
	else return false;
}
int main() {
	cin >> L >> C;
	pw = vector<char>(C);
	for (int a = 0; a < C; a++) {
		cin >> pw[a];

	}
	for (int b = 0; b < L; b++) {
		com.push_back(1);
	}
	for (int b = 0; b < C - L; b++) {
		com.push_back(0);
	}
	sort(com.begin(), com.end());
	sort(pw.begin(), pw.end());
	do {
		string tmp;
		for (int a = 0; a < C; a++) {
			if (com[a] == 1) {
				tmp.push_back(pw[a]);
			}
		}
		arr.push_back(tmp);
		tmp.clear();
	} while (next_permutation(com.begin(),com.end()));
	sort(arr.begin(), arr.end());
	for (int a = 0; a < arr.size(); a++) {
		if (Check(arr[a])) {
			cout << arr[a] << endl;
		}
	}
	return 0;
}