#include<iostream>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

int main(){
	fastio;
	int n;
	cin>>n;
	int num[n];
	int dp[n];
	for(int i=0;i<n;i++) cin>>num[i];
	
	int ans=dp[0]=num[0];
	for(int i=1;i<n;i++){
		dp[i]=max(dp[i-1]+num[i],num[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	
	return 0;
}
