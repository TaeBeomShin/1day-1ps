#include<bits/stdc++.h>
using namespace std;

int A[1000];
int dp[1000];

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[i]>A[j]&&dp[j]>=dp[i]) dp[i]=dp[j]+1;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) ans=max(ans,dp[i]);
	
	cout<<ans;
}
