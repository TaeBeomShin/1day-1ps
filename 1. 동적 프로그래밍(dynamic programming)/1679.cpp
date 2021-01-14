#include<bits/stdc++.h>
using namespace std;

const int INF=100001;
int dp[INF]={0,1};//dp[i] i를 만드는데 사용되는 숫자의 개수. 
int main(){
	int n,m;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cin>>m;
	for(int i=1;i<=INF;i++)
		dp[i]=1e7;
		
	for(int i=0;i<n;i++)
		for(int j=1;j<=m;j++)
			dp[v[i]*j]=j;
		
	for(int i=1;i<=v[n-1]*m;i++){
		for(int j=1;j<=v[n-1]*m;j++){
			dp[i+j]=min(dp[i]+dp[j],dp[i+j]);
		}
	}
	
	int ans=0;
	for(int i=1;i<=INF;i++){
		if(dp[i]>m){
			ans=i;
			break;
		}
	}
	(ans%2==0)?cout<<"holsson win at "<<ans:cout<<"jjaksoon win at "<<ans;
}
	
