#include<bits/stdc++.h>
using namespace std;

int c,n,m,p;
float m1,p1;
int main(){	
	while(1){
		int dp[10001]={0,};
		
		cin>>n>>m1;
		if(n==0) break;
		m=100*m1;	
		
		for(int i=0;i<n;i++){
			cin>>c>>p1;
			p=p1*100;
			for(int j=p;j<=m;j++)
				dp[j]=max(dp[j],dp[j-p]+c);
		}
		cout<<dp[m]<<"\n";
	}
}
