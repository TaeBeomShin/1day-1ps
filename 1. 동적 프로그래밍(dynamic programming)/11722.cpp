#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n+1]={0,},dp[n+1]={0,};
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(arr[i]<arr[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	
	int maxn=0;
	
	for(int i=1;i<=n;i++)
		maxn=max(maxn,dp[i]);
		
	cout<<maxn;
} 
