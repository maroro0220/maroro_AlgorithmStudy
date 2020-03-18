#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		string str;
		string ans;
		int cnt = 0;
		cin >> str;
		cin >> ans;
		for(int i=0;i<N;i++){
			if (str[i] == ans[i]) cnt++;
		}
		cout << '#' << test_case <<' '<< cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}