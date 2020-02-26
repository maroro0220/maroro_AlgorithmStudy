/*
����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.

���� �Է� 1
3 1
���� ��� 1
1
2
3
���� �Է� 2
4 2
���� ��� 2
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int>chk;
vector<int>num;
int N, M;
void dfs(int m) {
	if (m > M) {

		for (int i = 1; i <= M; i++) {
			printf("%d ", num[i]);
		}
		printf("\n");
		return ;
	}
	for (int i = 1; i <= N; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			num[m] = i;
			dfs(m + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	chk = vector<int>(N + 1);
	num = vector<int>(N+1);

	//for (int i = 1; i <= N; i++) {
		dfs(1);
	//}
	return 0;
}