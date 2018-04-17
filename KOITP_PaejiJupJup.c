/*
N×N
격자로 이루어진 도시가 있다. 이 도시 군데군데에는 폐지가 버려져 있다.
범수는 가장 왼쪽 위 격자(1, 1)에서 출발하여 가장 오른쪽 아래 격자(N, N)까지 이동하며 폐지를 줍는데, 최단 경로를 따라가야만 한다.
즉, 인접한 오른쪽 칸 또는 아래쪽 칸으로만 이동할 수 있다.
이 때, 범수가 수집할 수 있는 폐지의 최대값을 출력하시오.
출발점과 도착점에 위치한 폐지 또한 주울 수 있다.

입력
첫 번째 줄에는 도시의 크기 N이 주어진다.
(2≤N≤200)두 번째 줄부터N개의 줄에 걸쳐 도시의 정보가 주어진다. 
도시의 정보 중i번째 줄의j번째 숫자는 격자(i,j)에 버려진 폐지의 양Aij을 나타낸다.(0≤Aij≤1000)

출력
범수가 주울 수 있는 최대 폐지 양을 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int main() {
	int** arr;
	int** chk;
	int N;
	scanf_s("%d", &N);
	arr = (int**)calloc(N+1, sizeof(int*));
	chk = (int**)calloc(N+1, sizeof(int*));
	for (int i = 0; i <= N; i++) {
		arr[i] = (int*)calloc(N+1, sizeof(int));
		chk[i] = (int*)calloc(N+1, sizeof(int));
		if(i>0)
		for (int j = 1; j <= N; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			chk[i][j] = arr[i][j] + MAX(chk[i - 1][j], chk[i][j - 1]);
		}
	printf("%d", chk[N][N]);



	
}