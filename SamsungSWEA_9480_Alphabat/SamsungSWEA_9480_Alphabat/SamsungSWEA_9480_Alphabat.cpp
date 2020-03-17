#include<vector>
#include<iostream>
#include<map>
using namespace std;
vector<string>words;
//vector<int>chk;
int cnt;
int N;
void Insert(int idx,map<char,int>*chk) {
	for (int i = 0; i < words[idx].size(); i++) {
		chk->insert({words[idx][i], 1});
	}
}
void Remove() {

}
void Dfs(int idx,map<char,int> m) {
	Insert(idx, &m);
	if (m.size() == 26) {
		cnt++;
		//return;
	}
	
	for (int i = idx + 1; i < N; i++) {
		Dfs(i,m);
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cnt = 0;
		words = vector<string>(N);
		map<char, int>chk;
		for (int i = 0; i < N; i++) {
			cin >> words[i];
		}
		for (int i = 0; i < N; i++) {
			Dfs(i, chk);
		}

		cout << '#' << test_case << ' ' << cnt << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}