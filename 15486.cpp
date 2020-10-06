#include<bits/stdc++.h>
using namespace std;

int t[1500002]={0,};//최대 크기 150만 
int p[1500002]={0,};
int dp[1500002]={0,};

int main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>p[i];
	}
	
	int mv=0;
	for(int i=1;i<=n+1;i++){
		mv=max(mv,dp[i]);
		if(i+t[i]>n+1) continue;
		dp[i+t[i]]=max(mv+p[i],dp[i+t[i]]);	
	}
	
	cout<<mv;
}
