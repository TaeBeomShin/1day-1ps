#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[10001]={1,};
int coins[101]={0,};
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>coins[i];
		if(coins[i]>k) coins[i]=0;//구하려는 금액보다 더 큰 금액의 동전. 
	}
	for(int i=1;i<=k;i++) dp[i]=100001;
	for(int i=0;i<n;i++) dp[coins[i]]=1; //coins[i]원을 만드는데 필요한 동전 개수.
	
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(i-coins[j]>0) dp[i]=min(dp[i],dp[i-coins[j]]+1);
		}
	}
	
	(dp[k]>100000)?cout<<-1:cout<<dp[k];
}
