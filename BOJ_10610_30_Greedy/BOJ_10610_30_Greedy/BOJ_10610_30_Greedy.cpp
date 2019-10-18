#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string N;
	cin >> N;
	long long sum = 0;

		for (int i = 0; i < N.size(); i++) {
			sum += N[i]-'0';
		}
		sort(N.begin(), N.end());
		if (sum % 3 == 0 && N[0] == '0') {
			reverse(N.begin(), N.end());
			cout << N << endl;
		}
		else cout << -1;
	
	return 0;
}

/* over
int N;
int main() {
	cin >> N;
	long long maxi = -1;
	long long tmp=N,cnt=0;
	while (tmp > 0) {
		tmp /= 10;
		cnt++;
	}
	vector<long long>num(cnt),idx(cnt);
	
	for (int i = 0; i < cnt; i++) {
		num[i] = N % 10;
		N /= 10;
	}
	sort(num.begin(), num.end());
	do {
		if (num[0] == 0)continue;
		long long num_tmp=0;
		for (int i = 0; i < num.size(); i++) {
			num_tmp = num_tmp * 10 + num[i];
		}
		if (num_tmp % 30 == 0) {
			maxi = max(maxi, num_tmp);
		}
	} while (next_permutation(num.begin(), num.end()));
	cout << maxi;
	return 0;
}
*/