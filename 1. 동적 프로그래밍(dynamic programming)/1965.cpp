#include<bits/stdc++.h>
using namespace std;
/*
	상자의 크기가 주어질 때 한번에 넣을 수 있는 최대 상자의 개수
	
	-> 최대 부분 증가 수열 구하는 문제 (n<=1000)
*/
int main(){
	int n;cin>>n;
	
	int arr[n+1]={0,};
	int dp[n+1]={0,};
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(ans,dp[i]);
	}
	
	cout<<ans;
} 
