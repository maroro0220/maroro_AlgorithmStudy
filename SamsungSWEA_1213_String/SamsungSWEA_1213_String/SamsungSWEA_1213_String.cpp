
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tmp;
		cin >> tmp;
		string target;
		string str;
		//scanf("%s", target);
		//scanf("%s", str);
		cin >> target;
		cin >> str;
		int j = 0;
		int cnt = 0;
		for (int i = 0; i < str.size(); ) {
			if (str[i] == target[j]) {
				j++;
			}
			else {
				j = 0;
				if (str[i] == target[0]) {
					j++;
				}
			}
			i++;
			if (j == target.size()) {
				j = 0;
				cnt++;
			}
		}
		printf("#%d %d\n", test_case, cnt);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}