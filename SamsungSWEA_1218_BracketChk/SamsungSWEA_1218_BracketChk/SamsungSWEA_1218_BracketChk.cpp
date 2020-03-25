
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int l;
		int res = 1;//1 is available
		cin >> l;
		char top,tmp;
		vector<char>brackets;
		for (int i = 0; i < l; i++) {
			cin >> tmp;
			if (brackets.empty()) {
				brackets.push_back(tmp);
			}
			else {
				top = brackets.back();
				if (tmp == '{' || tmp == '[' || tmp == '(' || tmp == '<') {
					brackets.push_back(tmp);
				}
				else if (top == '{' && tmp == '}') {
					brackets.pop_back();
				}
				else if (top == '(' && tmp == ')') {
					brackets.pop_back();
				}
				else if (top == '[' && tmp == ']') {
					brackets.pop_back();
				}
				else if (top == '<' && tmp == '>') {
					brackets.pop_back();
				}
				else {
					res = 0;
				}
			}
		}//end for
		printf("#%d %d\n", test_case, res);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}