#include<iostream>
#include<vector>
//#include <climits>
using namespace std;

int main() {
	int K, N;
	scanf("%d %d", &K, &N);
	vector<long long>lan_c(K);
	long long max = 0;
	for (int i = 0; i < K; i++) {
		scanf("%lld",&lan_c[i]);
		if (max < lan_c[i]) max = lan_c[i];
	}
	long long left = 0, right = 0xffffffff;//right=LLONG_MAX; 0x7fffffffffffffff //0xffffffff =2^32
	long long mid, sum,ans=0 ;
	while (left <= right) {
		mid = (left + right) / 2;
		sum = 0;
		for (int i = 0; i < K; i++) {
			sum += (lan_c[i]/mid);
		}
		if (sum < N) {
			right = mid -1;
		}
		else if(sum>=N) {
			left = mid +1;
			if (mid > ans) {
				ans = mid;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}