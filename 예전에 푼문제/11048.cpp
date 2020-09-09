#include<stdio.h>
#include<stdlib.h>

using namespace std;

int max(int a,int b){//최댓값 반환함수. 
	if(a>=b) return a;
	else return b;
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	
	int candy[N+1][M+1];
	int dp[N+1][M+1];
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&candy[i][j]);
		}
	}

	dp[1][1]=candy[1][1];
	
	for(int i=2;i<=N;i++) dp[i][1]=dp[i-1][1]+candy[i][1];
	for(int i=2;i<=M;i++) dp[1][i]=dp[1][i-1]+candy[1][i];
	
	for(int i=2;i<=N;i++){
		for(int j=2;j<=M;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+candy[i][j];
		}
	}
	
	printf("%d",dp[N][M]);
	
	return 0;
} 
