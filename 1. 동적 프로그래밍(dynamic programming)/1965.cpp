#include<bits/stdc++.h>
using namespace std;
/*
	������ ũ�Ⱑ �־��� �� �ѹ��� ���� �� �ִ� �ִ� ������ ����
	
	-> �ִ� �κ� ���� ���� ���ϴ� ���� (n<=1000)
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
