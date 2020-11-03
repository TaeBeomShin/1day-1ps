#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int sticker[100001][2];
int dp[100001][3];// 아무리 커도 정수범위 안이다. 
int main(){
	fastio;
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<2;i++){
			for(int j=1;j<=n;j++){
				cin>>sticker[j][i];
			}
		}
		dp[1][0]=0;
		dp[1][1]=sticker[1][0];
		dp[1][2]=sticker[1][1];
		for(int i=2;i<=n;i++){
			dp[i][0]=max(dp[i-1][1],dp[i-1][2]);
			dp[i][1]=max(dp[i-1][0],dp[i-1][2])+sticker[i][0];
			dp[i][2]=max(dp[i-1][0],dp[i-1][1])+sticker[i][1];
//			cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
		}
		cout<<max(max(dp[n][0],dp[n][1]),dp[n][2])<<"\n";
	}
	
	
	return 0; 
}
