#include <iostream>
using namespace std;
int main() {
	int arr[101][10] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) {
				arr[i][j] = 1;
			}
			else {
				if (j > 0) {
					arr[i][j] += arr[i - 1][j - 1];
				}
				if(j<9){
					arr[i][j] += arr[i - 1][j + 1];
				}
		//		arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
				arr[i][j] %= 1000000000;
		//	}
		}
		//arr[i][0] += arr[i-1][1];
		//arr[i][9] += arr[i - 1][8];
		//arr[i][0] %= 1000000007;
		//arr[i][9] %= 1000000007;
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum+=arr[n][i];
		sum %= 1000000000;
	}
	//cout << sum;
	printf("%lld", sum);
	return 0;
}