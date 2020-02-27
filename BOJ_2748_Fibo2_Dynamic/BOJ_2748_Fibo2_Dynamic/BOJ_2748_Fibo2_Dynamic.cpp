
/*
�Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.

�̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n>=2)�� �ȴ�.

n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. n�� 90���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� n��° �Ǻ���ġ ���� ����Ѵ�.
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