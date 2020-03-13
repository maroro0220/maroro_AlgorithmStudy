
#include<iostream>
#include<queue>
#include<vector>
using namespace std;	
struct Mark
{
	int r,c;
};
//vector<vector<int>> chk;
vector<vector<char>> map;
int N, M;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
void Pmap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout<<map[i][j]<<' ';
		}
		cout << endl;
	}
	cout << endl;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		queue<Mark>qd, qs;
		cin >> N >> M;
		Mark sm, dm;
		map = vector<vector<char>>(N, vector<char>(M));
	//	chk = vector<vector<int>>(N, vector<int>(M, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'S') { sm.r = i; sm.c = j; qs.push(sm); }
				else if (map[i][j] == '*') { dm.r = i; dm.c = j; qd.push(dm); }
			}
		}
		int cnt = 0;
		bool c = false;
		int res;
		//Pmap();
		while (!qs.empty()) {
			int size = qd.size();
			int next_der, next_dec, next_sur, next_suc;
			Mark tmp;
			for (int j = 0; j < size; j++) {
				int now_der = qd.front().r;
				int now_dec = qd.front().c;
				qd.pop();
				for (int i = 0; i < 4; i++) {
					next_der = now_der + dr[i];
					next_dec = now_dec + dc[i];
					if (next_der >= 0 && next_der < N && next_dec >= 0 && next_dec < M) {
						if ((map[next_der][next_dec] == 'S' || map[next_der][next_dec] == '.')&& map[next_der][next_dec] != 'D') {
							map[next_der][next_dec] = '*';
							tmp.r = next_der; tmp.c = next_dec;
							qd.push(tmp);
						}
					}
				}
			}
		//	Pmap();
			size=qs.size();
			cnt++;
			for (int j = 0; j < size; j++) {
				int now_sur = qs.front().r;
				int now_suc = qs.front().c;
				qs.pop();
				for (int i = 0; i < 4; i++) {
					next_sur = now_sur + dr[i];
					next_suc = now_suc + dc[i];
					if (next_sur >= 0 && next_sur < N && next_suc >= 0 && next_suc < M) {
						if (map[next_sur][next_suc] == '.') {
							map[next_sur][next_suc] = 'S';
							
							tmp.r = next_sur; tmp.c = next_suc;
							qs.push(tmp);
						}
						if (map[next_sur][next_suc] == 'D') {
							//end
							c = true;
							res = cnt;
							
							//cout << '#' << test_case << ' ' << cnt << endl;
						}
					}
				}
			}
		//	Pmap();
		}
		if (c) {
			cout << '#' << test_case << ' ' << res << endl;
		}
		else {
			cout << '#' << test_case << " GAME OVER"<< endl;
		}



	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}