
#include<iostream>
using namespace std;
int solution(int n)
{
	int answer = 2;
	int t=0, f=0;
	int tmp;
	for (int i = 1; i <= n; i++) {
		tmp = i;
		while (tmp % 5 == 0) {
				f++;
				tmp /= 5;
		}
	}
	answer = f;
	return answer;
}

int main() {
	printf("%d\n", solution(5));
	printf("%d\n", solution(10));
	/*
	for (int i = 2; i < 100; i++) {
		printf("%d\n",solution(i));
	}
	*/
	
	return 0;
}
