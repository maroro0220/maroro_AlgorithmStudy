#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int N;
	int tmp;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; i++) {
		//cout << arr[i] << endl;
		printf("%d\n", arr[i]);
	}
	/*
	set<int> arr;
	set<int>::iterator iter;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.insert(tmp);
	}
	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		cout << *iter << " "<<endl;

	}
	*/
	return 0;
}