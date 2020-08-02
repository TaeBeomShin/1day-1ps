#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	if(a>=b) return a;
	else return b;
}
//더간결한 max 표현
/*
int max(int a,int b){
	return a>b?a:b;
}
*/ 
int main(){
	int N;
	scanf("%d",&N);
	int T[N+1]={0,};
	int P[N+1]={0,};
	int dp[N+1]={0,};
	
	for(int i=1;i<=N;i++){
		scanf("%d %d",&T[i],&P[i]);
	}
	
	//for(int i=1;i<=N;i++) printf("%d\n",T[i]);
	int result=0;
	for(int i=1;i<=N;i++){
		//i번째날에 일을 할경우. 
		if(i+T[i]<=N+1){//N+1번째 날까지 비교함. 
			dp[i+T[i]]=max(dp[i+T[i]],dp[i]+P[i]);
			result=max(result,dp[i+T[i]]);
		}
		//i번째날에 일을 하지 않을경우. 
		dp[i+1]=max(dp[i+1],dp[i]);
		result=max(result,dp[i+1]);
	}
	
	printf("%d",result);
	
	return 0;
}
