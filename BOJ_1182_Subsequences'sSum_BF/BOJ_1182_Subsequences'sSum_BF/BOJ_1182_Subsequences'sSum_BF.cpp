/*
#include<iostream>
#include<vector>

using namespace std;

int N, S;
vector<int> arr,tmp;
int cnt;
void dfs(int n,int sum) {

	sum += arr[n];
	if (n >= N) return;
	if (sum == S) { cnt++;  }
	dfs(n + 1, sum - arr[n]);
	dfs(n + 1, sum);
}
int main() {
	cin >> N >> S;
	arr = vector<int>(N+1);
	for (int i = 0; i < N; i++) {
		cin>>arr[i];
	}
	//for (int i = 1; i <= N; i++) {
		dfs(0,0);
	//}
		cout << cnt<<endl;
	return 0;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, S;
int main() {
	cin >> N >> S;
	/*
	if (N == 1 && S != N) {
		cout << 0;
		return 0;
	}*/
	vector<int> arr(N);
	int cnt = 0;
	for (int a = 0; a < N; a++) {
		cin >> arr[a];
	}//end for a
	if (N == 1 && S != arr[0])
	{
		cout << 0;
		return 0;
	}

	for (int a = 1; a <= N; a++) {
		vector<int> idx;
		int sum;
		for (int b = 0; b <a; b++) {
			idx.push_back(1);
		}
		for (int c = 0; c < N-a; c++) {
			idx.push_back(0);
		}
		sort(idx.begin(), idx.end());
		do {
			sum = 0;
			for (int d = 0; d < N;d++) {
				if (idx[d]) {
					sum += arr[d];
				}
			}
			if (sum == S) cnt++;
		} while (next_permutation(idx.begin(),idx.end()));

	}//end for a
	cout << cnt;
	return 0;
}
