
#include<iostream>
#include<vector>
using namespace std;
vector<int>arr[100];
int empt, len;
int res;
int dfs(int idx) {
	int next;
	for (int i = 0; i < arr[idx].size(); i++) {
		next = arr[idx][i];
		if (arr[idx][i] == 99) { res = 1; return res; }
		dfs(arr[idx][i]);
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		//int arr[100][2] = { 0 };
		cin >> empt >> len;
		int start, dest;
		res = 0;
		//vector<vector<int>>arr(100, vector<int>());
		bool chk = false;
		
		for (int i = 0; i < 100; i++) {
			arr[i]=vector<int>();
		}
		for (int i = 0; i < len; i++) {
			cin >> start >> dest;
			arr[start].push_back(dest);
			if (dest == 99)chk = true;
		}
		if(chk) dfs(0);
		printf("#%d %d\n", test_case, res);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}