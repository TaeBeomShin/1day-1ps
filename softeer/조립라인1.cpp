#include<bits/stdc++.h>
using namespace std;

int n;
int A[1001],B[1001],moveA[1000],moveB[1000];
int dp[1001][2]={0,};
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>A[i]>>B[i]>>moveB[i]>>moveA[i];
	}
	cin>>A[n]>>B[n];
	dp[1][0]=A[1];dp[1][1]=B[1];
	
	for(int i=2;i<=n;i++){
		dp[i][0]=min(dp[i-1][0]+A[i],dp[i-1][1]+A[i]+moveA[i-1]);
		dp[i][1]=min(dp[i-1][1]+B[i],dp[i-1][0]+B[i]+moveB[i-1]);
	}
	
	cout<<min(dp[n][0],dp[n][1]);
}
