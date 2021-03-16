#include<bits/stdc++.h>
using namespace std;

int n,k;
int line[101][101]={0,};//line[i][j] i번째 공장의 j번째 작업의 작업시간.
int moveto[101][101][101]={0,};//move[i][k][j] i번째 공장에서 k번째 공장으로의 이동시간 j번째 작업이 끝난후. 
int dp[101][101]={0,};//i번째 공장에서 j번째 작업까지 하는데 걸린시간. 
int main(){
	cin>>n>>k;
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=k;i++) cin>>line[i][j];
		if(j==n) break;
		for(int i=1;i<=k;i++){
			for(int s=1;s<=k;s++){
				if(i==s) continue;
				cin>>moveto[i][s][j];
//				cout<<moveto[i][s][j]<<"\n";
			}	
		}
	}
	
	for(int i=1;i<=k;i++){//i~k, 1번째 작업에 대해 초기화. 
		dp[i][1]=line[i][1];
	}
	 
	for(int j=2;j<=n;j++){//j번째 작업
		for(int i=1;i<=k;i++){
			dp[i][j]=dp[i][j-1]+line[i][j];
			for(int s=1;s<=k;s++){
				if(i==s) continue;//같은 공장이라면 돌아감. 
				dp[i][j]=min(dp[i][j],dp[s][j-1]+line[i][j]+moveto[s][i][j-1]);
			}
		}
	}
	
	int ans=1e9;
	for(int i=1;i<=k;i++) ans=min(ans,dp[i][n]);
	cout<<ans;
}
