#include<bits/stdc++.h>
using namespace std;

int c[1001][3];//0 : 빨강, 1: 초록, 2: 파랑 
int dp[1001][3];
int main(){
	int n;cin>>n;
	/*
		1번 집의 색은 2번 집의 색과 같지 않아야 한다.
		N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
		i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
	*/
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++){
			cin>>c[i][j];
			dp[i][j]=1001;
		}
	
	dp[1][0]=c[1][0];dp[1][1]=c[1][1];dp[1][2]=c[1][2];
	
	for(int i=2;i<=n;i++){
		//i번째 집을 빨강색으로 색칠. 
		dp[i][0]=min(dp[i-1][1]+c[i][0],dp[i-1][2]+c[i][0]);
		dp[i][1]=min(dp[i-1][0]+c[i][1],dp[i-1][2]+c[i][1]);
		dp[i][2]=min(dp[i-1][1]+c[i][2],dp[i-1][0]+c[i][2]);
	}
	cout<<min(dp[n][0],min(dp[n][1],dp[n][2]));
}
