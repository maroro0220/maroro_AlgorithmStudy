
/*
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 90보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 출력한다.
*/#include<iostream>
#include<vector>
using namespace std;
int n;
vector<long long>dp;
long long dfs(int N) {
	if (N == 1) {
		return 1;
	}
	if (N == 0) {
		return 0;
	}
	if (dp[N]) {
		return dp[N];
	}
	else {
		dp[N]= dfs(N - 1) + dfs(N - 2);
	}
	return dp[N];
}
int main() {
	cin >> n;
	dp = vector<long long>(n+1,0);
	dp[0] = 0; dp[1] = 1;
	/*
	for (int i = 2; i <dp.size(); i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	*/
	printf("%lld", dfs(n));
	return 0;
}