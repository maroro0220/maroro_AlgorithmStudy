
#include<iostream>
#include<string>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;
string str;
int num, cnt;
int chk = 0, cng = 0;
int mx;
bool c = false;
/*
void swp(string &s,int a,int b) {
	char tmp;
	tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}
*/
void Find(string st,int posi,int ct) {
	if (ct >= cnt) {
		int it = stoi(st);
		mx = MAX(mx, it);
		return;
	}
	for (int i = posi; i < st.size(); i++) {
		for (int j = i + 1; j < st.size(); j++) {

			if(st[i]<=st[j]){
				swap(st[i], st[j]);
				Find(st, i,ct + 1);
				swap(st[i], st[j]);

			}
		}
	}
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//vector<char> arr;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> num >> cnt;
		str = to_string(num);
		mx = 0;
		Find(str, 0,0);
		cout << '#' << test_case << ' ' << mx<<endl;
		str.clear();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}