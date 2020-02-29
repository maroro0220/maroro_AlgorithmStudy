
#include<iostream>
#include<string>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
string str;
void swp(int a,int b) {
	char tmp;
	tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//vector<char> arr;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num, cnt,mx,chk;
		cin >> num >> cnt;
		str = to_string(num);
		for (int i = 0; i < cnt; i++) {
			mx = str[i];
			//for (int j = i+1; j < str.size(); j++) {
			for(int j=str.size()-1;j>i;j--){
				if (mx < MAX(mx, str[j])) {
					mx = str[j];
					chk = j;
				}
			}
			swp(i, chk);
		}
		cout << '#' << test_case << ' ' << str<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}