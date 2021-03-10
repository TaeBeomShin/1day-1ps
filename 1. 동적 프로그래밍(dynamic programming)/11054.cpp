#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 11054 - DP(2���� dp) 
	
	dp[i]�� i�� ������ 1~i������ �����ϴ� ���� �� �κм����� ����
	dp2[i]�� i�� ������ i~n������ �����ϴ� ���� �� �κм����� ����
	
	�̴�.   
*/
int dp[1001],dp2[1001],A[1001];
int main(){
	int n;cin>>n;
	
	for(int i=1;i<=n;i++) cin>>A[i];
	
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(A[j]<A[i]) dp[i]=max(dp[i],dp[j]+1);
		}
	}

	int ans=0;
	for(int i=n;i>=1;i--){
		dp2[i]=1;
		for(int j=n;j>=i;j--){
			if(A[j]<A[i]) dp2[i]=max(dp2[i],dp2[j]+1);
		}
		ans=max(ans,dp[i]+dp2[i]-1);
	}
	cout<<ans;
}
