
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int N;
vector<int> arr;
vector<int>chk;
set<int> res;
int tmp;
/*
int n;
void dfs(int idx, int cnt) {
	if (cnt == n) {
		res.insert(tmp);
		//cout << tmp << endl;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (chk[i])continue;
		chk[i] = 1;
		tmp += arr[i];
		dfs(i, cnt + 1);
		tmp -= arr[i];
		chk[i] = 0;
	}
}
*/
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		arr = vector<int>(N);
		chk = vector<int>(10010, 0);

	
		int maxi = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			maxi += arr[i];
		}	
		chk[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = maxi; j >= 0; j--) {
				if ((j+arr[i])<=maxi && chk[j]) {
				//if(chk[j]){
					chk[j + arr[i]] = 1;
				}
			}
		}
		
		/* time out
		for (int i = 1; i <= N; i++) {
			vector<int> ind;

			ind.clear();
			for (int j = 0; j < i; j++) {
				ind.push_back(1);
			}
			for (int k = 0; k < N - i; k++) {
				ind.push_back(0);
			}
			sort(ind.begin(),ind.end());
			do {
				int tmp = 0;
				for (int a = 0; a < ind.size(); a++) {
					if (ind[a]) {
						tmp += arr[a];
						//cout << tmp << endl;
					}
				}
				res.insert(tmp);
			} while (next_permutation(ind.begin(), ind.end()));
		}
		*/
		/*
		for (int i = 0; i < N; i++) {
			n = i;
			dfs(0, 0);
		}*/
		int cnt = 0;
		
		for (int i = 0; i < 10001; i++) {
			if (chk[i]) {
				cnt++;
			}
		}
		
		
		cout << '#' << test_case << ' ' << cnt << endl;
		//cout << '#' << test_case << ' ' << res.size()+1 << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}