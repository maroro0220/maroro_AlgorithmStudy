/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include<stdlib.h>
#define MAX(X,Y) ((X)<(Y)?(X):(Y))
int Answer;

int main(void)
{
	int T, test_case,N,M, a, b, l;
	int** arr;
	int** chk;
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
	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d",&N,&M);
		int* chn;
//		int arr[500][500]={0,};
//		int chk[500][500]={0,};
		arr=(int**)calloc(N+1,sizeof(int*));
		chk=(int**)calloc(N+1,sizeof(int*));
		for(int i=0;i<=N;i++){
			arr[i]=(int*)calloc(N+1,sizeof(int));
			chk[i]=(int*)calloc(N+1,sizeof(int));
		}
		chn=(int*)calloc(N+1,sizeof(int));

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
		for(int i=0;i<M;i++){
			scanf("%d %d %d",&a,&b,&l);
			arr[a][b]=l;
			arr[b][a]=l;
		}
		for(int k=1;k<=N;k++){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					if(i<j)
					if((i!=j) && (arr[i][k]) && arr[k][j] &&(!arr[i][j] || (arr[i][j]>arr[i][k]+arr[k][j]))){
							arr[i][j]=arr[i][k]+arr[k][j];
							chk[i][j]=k;
//						else{ //arr[i][j]!=0
//							if(arr[i][j]>arr[i][k]+arr[k][j]){
//								chk[i][j]=k;
//								arr[i][]
//							}
//							arr[i][j]=MIN(arr[i][j],arr[i][k]+arr[k][j]);
						//}//end if
					}//end if
				}//end for k
			}//end for i
		}//end for k
//	    for(int i=1;i<=N;i++){
//	      printf("chk[%d] =", i);
//	      for(int j=1;j<=N;j++){
//	        printf(" %d",chk[i][j]);
//	      }
//	      printf("\n");
//	    }

		int sum=0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
//				printf("arr[%d][%d]=%d",i,j,arr[i][j]);
				if(i<j)
					if(chk[i][j]!=0)
						chn[chk[i][j]]++;
				}
//			printf("\n");
			}
		for(int i=1;i<=N;i++){
//			printf("chn[%d]=%d",i,chn[i]);
			if(!chn[i]){
				sum++;
			}
		}
//		for(int i=0;i<=N;i++){free(arr[i]);free(chk[i]);}
//			free(arr);
//			free(chk);
		printf("Case #%d\n", test_case+1);
		if(sum==0){
					printf("0");
		}
		else{
			printf("%d",sum);
			for(int i=1;i<=N;i++){
			if(!chn[i]){
				printf(" %d",i);
			}
		}
		}

//		free(chn);
		printf("\n");
	}

	return 0;//Your program should return 0 on normal termination.
}
