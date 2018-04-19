/*정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int T,n;
	
	scanf("%d", &T);
	while (T--) {
		int arr[12] = { 0, };
		scanf("%d", &n);
		arr[0] = 1;
		for (int i = 0; i <= n; i++) {
			if (i - 1 >= 0) {
				arr[i] += arr[i - 1];
			}if (i - 2 >= 0) {
				arr[i] += arr[i - 2];
			}if (i - 3 >= 0) {
				arr[i] += arr[i - 3];
			}		
		}
		printf("%d\n", arr[n]);
	}
}