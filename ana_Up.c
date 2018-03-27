#include<stdio.h>
#include<string.h>
#define MAX 255
#define ALPHA 52

int anagram_test(char* a1, char* a2){
	   int c1[ALPHA]={0,},c2[ALPHA]={0,},i;
	   if(strlen(a1)==strlen(a2)){
	      i=0;
	      while(a1[i]!='\0'){
	    	  if(a1[i]>='a' && a1[i]<='z'){
	    		  c1[a1[i]-'a']++;
	    	  }
	    	  else if(a1[i]>='A' && a1[i]<='Z'){
	    		  c1[a1[i]-'A'+26]++;
	    	  }
	    	  if(a2[i]>='a' && a2[i]<='z'){
	    		  c2[a2[i]-'a']++;
	    	  }
	    	  else if(a2[i]>='A' && a2[i]<='Z'){
	    		  c2[a2[i]-'A'+26]++;
	    	  }
	         i++;
	      }
	      int cnt=0;
	      for(int j=0;j<52;j++){
	         if(cnt==strlen(a1)){
//	            printf("\nAnagram ok");
	        	 return 0;
	         }
	         if(c1[j]==c2[j]){
	            cnt++;
	            continue;
	         }
	         else{
//	            printf("not ana");
	        	 return 1;
//	            break;
	         }
	      }
	   }
	   else
		   return 1;
//	      printf("\nnot anagram");
}
int main(){
   char a1[MAX],a2[MAX];
   printf("first");
   fflush(stdout);
   scanf("%s",a1);
   printf("\nsecond");
   fflush(stdout);
   scanf("%s",a2);
   switch(anagram_test(a1,a2)){
   case 0:
	   printf("ok Ana");
	   break;
   case 1:
	   printf("not Ana");
	   break;
   default:
	   printf("error");
   }
   return 0;
}
