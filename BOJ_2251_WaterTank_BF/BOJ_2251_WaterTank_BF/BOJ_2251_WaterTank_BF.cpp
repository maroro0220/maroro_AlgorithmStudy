#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int A, B, C;
vector<int>res;
struct WaterTank
{
	int a, b, c;
};
queue<WaterTank> q;
vector<vector<vector<int>>>chk(201, vector<vector<int>>(201, vector<int>(201, 0)));
void bfs() {

	q.push({ 0,0,C });
	WaterTank cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		if (chk[cur.a][cur.b][cur.c]) {
			continue;
		}
		chk[cur.a][cur.b][cur.c] = 1;
		if (cur.a == 0) res.push_back(cur.c);//A=0

		//A->B
		if (cur.a + cur.b > B) { //b is over
			q.push({ cur.a + cur.b - B , B, cur.c });
		}
		else {
			q.push({ 0,cur.a + cur.b,cur.c });
		}
		//A->C
		if (cur.a + cur.c > C) { //C is over
			q.push({ cur.a + cur.c - C , cur.b, C });
		}
		else {
			q.push({ 0,cur.b,cur.a + cur.c });
		}
		//B->A
		if (cur.a + cur.b > A) { //A is over
			q.push({ A , cur.a + cur.b - A, cur.c });
		}
		else {
			q.push({ cur.a + cur.b, 0,cur.c });
		}
		//B->C
		if (cur.c + cur.b > C) { //C is over
			q.push({ cur.a , cur.c + cur.b - C, C });
		}
		else {
			q.push({ cur.a, 0,cur.c + cur.b });
		}
		//C->A
		if (cur.c + cur.a > A) { //A is over
			q.push({ A , cur.b, cur.c + cur.a - A });
		}
		else {
			q.push({ cur.a + cur.c, cur.b, 0 });
		}
		//C->B
		if (cur.c + cur.b > B) { //C is over
			q.push({ cur.a , B, cur.c + cur.b - B });
		}
		else {
			q.push({ cur.a, cur.c + cur.b, 0 });
		}
	}
}
int main() {
	cin >> A >> B >> C;
	bfs();
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	return 0;
}