#include<bits/stdc++.h>
using namespace std;

int dp[100001]={0,1,2,3,1,};
int main(){
	int n;cin>>n;
	// 1=1, 2=1+1,3=1+1+1,4=2^2,5=;
	
	for(int i=5;i<=100001;i++) dp[i]=100001;
 
	for(int i=1;i<=n;i++){
		for(int j=2;j*j<=i;j++){
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
	}
	cout<<dp[n];
}
