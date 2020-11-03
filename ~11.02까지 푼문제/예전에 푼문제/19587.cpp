#include<iostream>
using namespace std;

int main(){
	unsigned long long N;
	cin>>N;
	unsigned long long dp[(N+1)][3];
	dp[1][0]=dp[1][1]=dp[1][2]=1;
	for(int i=2;i<=N;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%(1000000007);
		dp[i][1]=(dp[i-1][0]+dp[i-1][2])%(1000000007);
		dp[i][2]=(dp[i-1][0]+dp[i-1][1])%(1000000007);
	}
	
	cout<<(dp[N][0]+dp[N][1]+dp[N][2])%(1000000007);
	
	return 0;
}
