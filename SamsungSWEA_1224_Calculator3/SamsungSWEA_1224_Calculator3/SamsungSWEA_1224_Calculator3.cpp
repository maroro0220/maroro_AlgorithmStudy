#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	//cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int len;
		scanf("%d", &len);
		vector<char>num;
		vector<char>ch;
		char tmp;
		for (int i = 0; i < len; i++) {
			scanf(" %c", &tmp);
			if (tmp >= '0' && tmp <= '9') {
				num.push_back(tmp);
			}
			else if (tmp == '(') {
				ch.push_back(tmp);
			}
			else if (tmp == ')') {
				char now;
				while (1) {
					now=ch.back();
					ch.pop_back();
					if (now == '(') {
						break;
					}
					if (now == '+') {
						while (ch.back() == '*') {
							num.push_back(ch.back());
							ch.pop_back();
						}
					}
					num.push_back(now);
				}
			}
			else if (tmp == '+') {
				while (!ch.empty()&&ch.back() == '*') {
					int now = ch.back();
					ch.pop_back();
					num.push_back(now);
				}
				ch.push_back(tmp);
			}
			else if (tmp == '*') {
				ch.push_back(tmp);
			}	
		}

		while(!ch.empty()){
			char now = ch.back();
			ch.pop_back();
			if (now == '(') break;
			num.push_back(now);
		}
		for (int i = 0; i < num.size(); i++) printf("%c ",num[i]);
		vector<int>calc;
		for (int i = 0; i < num.size(); i++) {
			char now = num[i];
			if (now == '+') {
				int s = calc.back();
				calc.pop_back();
				s += calc.back();
				calc.pop_back();
				calc.push_back(s);
			}
			else if (now == '*') {
				int s = calc.back();
				calc.pop_back();
				s *= calc.back();
				calc.pop_back();
				calc.push_back(s);
			}
			else if (now >= '0' && now <= '9') {
				calc.push_back(now-'0');
			}
		}
		printf("#%d %d\n",test_case, calc[0]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}