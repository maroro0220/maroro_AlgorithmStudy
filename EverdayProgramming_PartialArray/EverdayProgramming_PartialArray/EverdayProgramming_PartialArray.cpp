/*
���� �迭�� �־����� ��, ���� �ִ밡 �Ǵ� �κ� �迭�� ���� ���Ͻÿ�.
��, �κ� �迭�� ���ҵ��� ���ӵ� ���ҵ�� �����Ǿ�� �մϴ�.
Input: [-2, 1, -3, 4, -1, 2, 1, -5, -4]
Output: 6 (�κ� �迭�� [4, -1, 2, 1])

Input: [-8, -3, -6, -2, -5, -4]
Output: -2 (�κ� �迭�� [-2])
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	//vector<int> arr1,arr2;
	// arr1 = { -2, 1, -3, 4, -1, 2, 1, -5, -4 };//6 (4,-1,2,1)
	// arr2 = { -8, -3, -6, -2, -5, -4 };
	vector<int> arr;
	vector<int> dp;
	//vector<int>dp1(arr1.size(), 0);
	//dp1[0] = arr1[0];
	int maxi= -9999999999;
	arr= { -2, 1, -3, 4, -1, 2, 1, -5, -4 };
	dp = vector<int>(arr.size(), 0);
	dp[0] = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (maxi < dp[i]) maxi = dp[i];
	}
	cout << maxi << endl;

	maxi = -9999999999;
	arr.clear();
	arr = { -8, -3, -6, -2, -5, -4 };
	dp = vector<int>(arr.size(), 0);
	for (int i = 1; i < arr.size(); i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (maxi < dp[i]) maxi = dp[i];
	}
	/*
	for (int i = 1; i < arr1.size(); i++) {
		dp1[i] = max(dp1[i - 1] + arr1[i], arr1[i]);
		if (maxi < dp1[i]) maxi = dp1[i];
	}
	cout << maxi << endl;
	vector<int>dp2(arr2.size(), 0);
	dp2[0] = arr2[0];
	maxi = -9999999999;
	for (int i = 1; i < arr2.size(); i++) {
		dp2[i] = max(dp2[i - 1] + arr2[i], arr2[i]);
		if (maxi < dp2[i]) maxi = dp2[i];
	}
	*/
	cout << maxi<< endl;
	return 0;
}