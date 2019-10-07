#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> prime(2);
vector<int>num,resP;
void Prime() {
num = vector<int>(prime[1]+1, 1);
		for (int i = 2; i <= sqrt(9999); i++) {
			if (num[i] == 0) continue;
			for (int j = i * 2; j <= 9999; j += i) {
				num[j] = 0;
			}
		}

		for (int a = 1000; a <10000; a++) {
			if (num[a] == 1) {
				resP.push_back(num[a]);
				//cout << a<<' ';
			}
		}
		//cout << endl;
}
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> prime[0] >> prime[1];
		
	}//end for test case
	return 0;
}