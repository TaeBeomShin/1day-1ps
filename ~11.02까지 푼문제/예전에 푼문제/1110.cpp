#include<stdio.h>
#include<stdlib.h>

int main(){
	int N;
	scanf("%d",&N);
	int original =N;
	 
	N= N%10*10+(N/10+N%10)%10;
	int count=1;
	
	while(original!=N){
		N= N%10*10+(N/10+N%10)%10;
		count++;
	}
	
	printf("%d",count);
	return 0;
}
