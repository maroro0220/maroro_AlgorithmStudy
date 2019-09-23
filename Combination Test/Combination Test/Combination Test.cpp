#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> arr;
vector<int> tmp;
vector<int>t; 
vector<int>chk(10,0);
void dfs(int idx, int cnt ) {
	if (cnt == n) {
		int tt = 0;
		for (int i = 0; i <n; i++) {
			tt +=tmp[i] *pow(10, n-1-i);
		}
		arr.push_back(tt);
		cout << tt << endl;
		//tmp.clear();
		return;
	}//end if cnt==n
	for (int i = 0; i < n;i++) {
		if (!chk[i]) {
			chk[i] = 1;
			tmp.push_back(t[i]);
			dfs(i,cnt + 1);
			chk[i] = 0;
			tmp.pop_back();
		}
	}
	//return;

}
int main() {
	int a;
	cin >> n;
	vector<int>chk(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		t.push_back(a);
	}
	dfs(0,0);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	return 0;
}