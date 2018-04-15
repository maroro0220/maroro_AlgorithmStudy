/*
 * swexpert_1204_numFreq.c
 *
 *  Created on: 2018. 4. 13.
 *      Author: maroro
 */


#include<stdio.h>
//#define MAX((X),(Y)) ((X)>(Y)?(X):(Y))
int main(){
int T;
//    scanf("%d",&T);
    T=10;
    while(T--){
        int t,arr[1000],chk[101]={0,},max=0,m=0;

        scanf("%d",&t);
        for(int i=0;i<1000;i++){
        	scanf("%d",&arr[i]);
            chk[arr[i]]++;
        }
        for(int i=0;i<101;i++){
//            printf("%d",chk[i]);
       		if(max<=chk[i]){
                max=chk[i];
            	m=i;
            }
        }
        printf("#%d %d\n",t,m);

    }

}
