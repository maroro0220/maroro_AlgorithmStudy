#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int k=1;
	while (k) {
		cin >> k;
		if (!k) break;
		vector<int> lot(k),idx;
		for (int i = 0; i < k; i++) {
			cin >> lot[i];
		}
		for (int a = 0; a < 6; a++) {
			idx.push_back(1);
		}
		for (int a = 0; a < k-6; a++) {
			idx.push_back(0);
		}
		sort(idx.begin(), idx.end());
		int cnt = 0;
		vector < vector<int>> res;
		vector<int>tmp;
		do {
			tmp.clear();
			for (int i = 0; i < k; i++) {
				if (idx[i] == 1) {
					tmp.push_back(lot[i]);
					//cout << lot[i] << ' ';
				}
			}
			res.push_back(tmp);
		} while (next_permutation(idx.begin(), idx.end()));
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < 6; j++) {
				cout << res[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

}