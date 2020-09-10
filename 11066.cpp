#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int t,k,i;
//dp[i][j]= i번째 장부터 j번째 장까지 합치는데 드는 비용.
//dp[i][i]=cost[i], dp[i][i+1]=cost[i]+cost[i+1]
//dp[i][j]=(i<=k<j) min(dp[i][k]+dp[k+1][j]+psum[i][j]); 
int main(){
	cin>>t;
	while(t--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>cost[i];
			sum[i]=sum[i-1]+cost[i];//누적합을 구한다. 
		}
		for(int i=1;i<k;i++){
			for(int j=1;j+i<=k;j++){
				int k=i+j;
				dp[j][k]= INT_MAX;
				
				for(int l=j;l<k;l++)
					dp[j][k]=min(dp[j][k],dp[j][l]+dp[l+1][k]+sum[k]-sum[j-1]);
			}
		}
		cout<<dp[1][k]<<"\n";
	}
	
	return 0;
}
