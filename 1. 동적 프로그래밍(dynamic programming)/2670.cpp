#include<bits/stdc++.h>
using namespace std;

double arr[10001],dp[10001];
int main(){
	int n;cin>>n;//연속곱최대. 
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	double ans=arr[1];
	dp[1]=arr[1];
	for(int i=2;i<=n;i++){
		dp[i]=arr[i];
		dp[i]=max(dp[i],dp[i-1]*arr[i]);
		ans=max(ans,dp[i]);
	}
	printf("%.3lf",ans);
}
