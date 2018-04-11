/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <stdlib.h>
int Answer;

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);
	int i, n, k,l;
	int* a;
	scanf("%d", &T);
//	if(T<6 && T>0){
		for(test_case = 0; test_case < T; test_case++)
		{

			scanf("%d",&n);
			a=(int*)calloc(n+2,sizeof(int));
//			a[0]=0;
			for(i=1;i<=n;i++){
				scanf("%d ",&a[i]);
//				if(a[i]<1 || a[i]>1000000000){
//					i--;
//					continue;
//				}
				printf("ii:%d",i);
			}
//			a[i]=2000000001;
			printf("i:%d\n",i);
			scanf("%d",&k);
			l=0;
			Answer=0;
			i=0;
//			printf("\na[%d]=%d",0,a[0]);
//			for(int i=1;i<=n;){
//				printf("\na[%d]=%d",i,a[i]);
//				printf("\nl1: %d ",l);
				while((l<n)&&i<=n){
					while(a[l]+k>=a[i])i++;
					i--;
					printf("i:%d l:%d\n",i,l);
					if((i==l)){
						Answer=-1;
						break;
					}
					else if(i==(n+1)){
						Answer++;
						break;}
					Answer++;
					l=i;
//					printf("l:%d Ans:%d\n",l,Answer);
				}
//				if((a[i]>a[l]+k)&&flag){
//					l=i-1;
//					Answer++;
//					flag=0;
////					printf("l: %d",l);
//				}
//				else if(a[l]+k>=a[i]){
//					i++;
//					flag=1;
////					printf("i: %d",i);
//					if((i>n)){
//						Answer++;
//					}
//				}
//
//				else{
////					printf("err");
//					Answer=-1;
//					break;
//				}
//			}


		/////////////////////////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
			free(a);
			printf("Case #%d\n", test_case+1);
			printf("%d\n", Answer);
		}
//	}//if(T)

	return 0;//Your program should return 0 on normal termination.
}
