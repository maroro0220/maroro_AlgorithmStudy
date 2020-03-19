#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void Swap(vector<string>& st, int a, int b) {
	string tmp;
	tmp = st[a];
	st[a] = st[b];
	st[b] = tmp;
}
bool cmp(string s1, string s2) {
	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	else {
		return s1.length() < s2.length();
	}
}
int main(int argc, char** argv)
{
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);//없어도 됨
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		vector<string>name(N);
		for (int i = 0; i < N; i++) {
			cin >> name[i];
		}
		sort(name.begin(), name.end(),cmp);
		name.erase(unique(name.begin(), name.end()), name.end());
		/*
		//this is time over
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (name[i].length() > name[j].length()) {
					Swap(name, i, j);
				}
				else if (name[i].length() == name[j].length()) {
					if (!name[i].compare(name[j])) {
						name[j] = '-';
					}
					else {
						for (int a = 0; a < name[i].length(); a++) {
							if (name[i][a] < name[j][a]) break;
							else if (name[i][a] > name[j][a]) {
								Swap(name, i, j);
								break;
							}
						}
					}
				}
			}
		}
		*/
		cout << '#' << test_case << "\n"; //endl은 실패 
		for (int i = 0; i < name.size(); i++) {
			cout << name[i] << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}