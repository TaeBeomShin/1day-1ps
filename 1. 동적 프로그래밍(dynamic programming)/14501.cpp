#include<bits/stdc++.h>
using namespace std;
/*
	sol1) �������α׷���
	i���� ���� �� ���� ���� ���� ���� ���� ����� ����.
	1. ���� �ϴ� ���
		i+T[i]<=n+1�� ��, i���� ���� �� �� ����. -> dp[i+T[i]]=max(dp[i]+P[i],dp[i+T[i]]
	2. ���� ���� �ʴ� ���
		�������� �Ѿ��. 
*/
int T[17]={0,};
int P[17]={0,};
int dp[17]={0,};
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>T[i]>>P[i];
	
	for(int i=1;i<=n;i++){
		if(i+T[i]<=n+1) 
			dp[i+T[i]]=max(dp[i]+P[i],dp[i+T[i]]);
		dp[i+1]=max(dp[i+1],dp[i]);
	}
	
	int maxn=0;
	for(int i=1;i<=n+1;i++)
		if(dp[i]>maxn) maxn=dp[i];
	
	cout<<maxn;
} 
