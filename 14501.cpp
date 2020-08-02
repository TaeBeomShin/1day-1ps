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
	int T[17]={0,};//문제에서 주어진 공간이 작다면 되도록 크기를 적어주도록하자.
	int P[17]={0,};
	int dp[17]={0,};
	
	for(int i=1;i<=N;i++){
		scanf("%d %d",&T[i],&P[i]);
	}
	
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
//원래 O(N^2)인 코드를 작성하였으나, https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14501-%ED%87%B4%EC%82%AC-exjyfr5vgj를 참고하여 O(N)인 코드로 수정하였다.
//나중에 다시풀어봐야지..
