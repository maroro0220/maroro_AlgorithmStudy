/*���� 4�� 1, 2, 3�� �������� ��Ÿ���� ����� �� 7������ �ִ�.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
���� n�� �־����� ��, n�� 1,2,3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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