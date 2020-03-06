
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> encode;
		string tmp;

		cin >> tmp;
		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] >= 'A' && tmp[i] <= 'Z') tmp[i] -= 'A';
			else if (tmp[i] >= 'a' && tmp[i] <= 'z') tmp[i] = (tmp[i] - 'a') + 26;
			else if (tmp[i] >= '0' && tmp[i] <= '9') tmp[i] = (tmp[i] - '0') + 52;
			else if (tmp[i] == '+') tmp[i] = 62;
			else if (tmp[i] == '/') tmp[i] = 63;
		}
		encode = vector<int>((tmp.size()*0.75), 0);
		for (int i = 0; i <tmp.size(); i += 4) {
			encode[i*0.75] = ((tmp[i]) << 2) + ((tmp[i + 1] ) >> 4);
			encode[i*0.75+1] = ((tmp[i+1] ) << 4) + ((tmp[i + 2] ) >> 2);
			encode[i*0.75+2] = ((tmp[i+2] ) << 6) + (tmp[i + 3] );
		}
		cout << '#' << test_case << ' ';
		for (int i = 0; i < encode.size(); i++) {
			printf( "%c",encode[i]);
		}
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}