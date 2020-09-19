#include<bits/stdc++.h>
using namespace std;

int dp[301][301]={0,};

int main(){
	int n,m,k;
	int value=0;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>value;
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+value;
		}
	}
	cin>>k;
	int sum=0;
	int x1,x2,y1,y2;
	for(int i=0;i<k;i++){
		cin>>y1>>x1>>y2>>x2;
		sum=dp[y2][x2]-dp[y2][x1-1]-dp[y1-1][x2]+dp[y1-1][x1-1];
		cout<<sum<<"\n";
	}
}
