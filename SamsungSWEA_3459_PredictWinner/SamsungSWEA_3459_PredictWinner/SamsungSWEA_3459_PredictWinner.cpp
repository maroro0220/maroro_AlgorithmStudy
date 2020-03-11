
#include<iostream>
#include<stdio.h>
//#include<queue>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long N;
		scanf("%lld", &N);
		string res = "Bob";
		
		/*
		long long x = 1;
		long long cnt = 0;
		queue<long long> q;
		q.push(x);
		while (!q.empty()) {
			int s = q.size();
			cout <<"qsize : "<< s << endl;
			for (int i = 0; i < s; i++) {
				long long tmp = q.front();
				cout << "tmp: " << tmp << endl;
				q.pop();
				if ((tmp * 2 + 1 > N || tmp * 2 > N)) continue;
				else {
					q.push(tmp * 2 + 1);
					q.push(tmp * 2);
				}
			}
			cnt++;
			cout << "cnt: " << cnt << endl;
		}
		*/
		/*
		while (1) {
			if ( (x * 2 + 1) > N||x * 2 > N ) {
				break;
			}
			else if (x * 2 + 1 <= N) {
				cnt++;
				x = x * 2 + 1;
			}
			else if (x * 2 <= N) {
				cnt++;
				x *= 2;
			}
		}
		if (cnt % 2 == 0) {
			res = "Alice";
		}
		*/
		/*
		//Time over
		long long depth = 0ll;
		if (N == 1) { res = "Bob"; }
		else {
			depth = 1;
			while (1) {
				long long start, end;
				start = (1ll << depth);
				end = (start << 1);
				//cout <<N<<' '<< start << ' ' << end<<endl;
				if (N >= start && N < end) {
					//depth++;
					if (N < (start + end) / 2)res = "Alice";
					else res = "Bob";
					break;
				}
				else {
					depth++;
				}
			}
		}
		*/
		cout << '#' << test_case << ' ' << res<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}