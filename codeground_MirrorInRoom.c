/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include<stdlib.h>

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

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		char** a;
		int** chk_arr;
		int n;
		scanf("%d",&n);
		chk_arr=(int**)calloc(n,sizeof(int*));
		a=(char**) malloc(n*sizeof(char*));
		for(int i=0;i<n;i++){
			a[i]=(char*)malloc((n+1)*sizeof(char));
			chk_arr[i]=(int*)calloc(n,sizeof(int));
			scanf("%s",a[i]);
		}

		int cnt=0,i=0,j=0,dir=0;//from 0=left, 1=up, 2= right, 3=down
		while((i>=0) && (i<n) && (j>=0) && (j<n)){
			switch(a[i][j]){
			case '0':
				switch(dir){
				case 0:
					j++;
					break;
				case 1:
					i++;
					break;
				case 2:
					j--;
					break;
				case 3:
					i--;
					break;
				}
				break;
			case '1'://  /
				if(!chk_arr[i][j]){
					chk_arr[i][j]=1;
					cnt++;
				}
				switch(dir){
				case 0:
					i--;
					dir=3;
					break;
				case 1:
					dir=2;
					j--;
					break;
				case 2:
					dir=1;
					i++;
					break;
				case 3:
					dir=0;
					j++;
					break;
				}
				break;
			case '2':// '\'
				if(!chk_arr[i][j]){
					chk_arr[i][j]=1;
					cnt++;
				}
				switch(dir){
				case 0:
					dir=1;
					i++;
					break;
				case 1:
					dir=0;
					j++;
					break;
				case 2:
					dir=3;
					i--;
					break;
				case 3:
					dir=2;
					j--;
					break;
				}
				break;
			default:
				printf("error");
			}
		}
//
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
		Answer=cnt;
		free(a);
		free(chk_arr);
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
