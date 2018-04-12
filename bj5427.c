/*
 * bj5427.c
 *
 *  Created on: 2018. 4. 5.
 *      Author: maroro
 */


#include<stdio.h>
int w,h;
int fire(int** arr, int a, int b);
int main(){
	int T,a,b,i,j;
	scanf("%d %d %d",&T,&w,&h);
	int** arr=(int **)malloc(sizeof(int*)*h);
	for(i=0; i<h; i++){
	    arr[i] = (int*) malloc ( sizeof(int) * w);
	    scanf("%s",arr[i]);
	    if(!(i==0 || i==(h-1))){
	    	for(j=0; j<w;j++){
	    		if(arr[i][j]=='.')
	    			goto EXIT;
	    	}
	    }
	    else{
	    	for(j=0; j<w;j+=w-1){
	    		   if(arr[i][j]=='.')
	    			   goto EXIT;
	    }
	    	printf("IMPOSSIBLE");

	}
	EXIT:
		fire(arr,i,j);

	return 0;
}
int fire(int** arr,int a, int b){
	int Ans;
	for(int i=1;i<h-1;i++){
		for(int j=1;j<w-1;j++){
			if(arr[i][j]=='@'){
				break;
			}
		}
	}


	return Ans;
}
