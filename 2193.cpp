#include<iostream>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

int main(){
	fastio;
	int N;
	cin>>N;
	long long dp[91]={0,};
	
//N자리 이친수의 개수 구하기.(bottom-up) 
//1,10,100,101,1000,1001
//첫자리가 1이면 0밖에 못옴, 첫자리에는 0이 못옴.
//이차원 배열, dp[i][j] i는 숫자의 개수 j=0, 끝자리가 0, j=1, 끝자리가 1,
// dp[1][1]=1,dp[1][0]=0,dp[2][1]=0,dp[2][0]=1,dp[3][1]=1,dp[3][1]=1;
// dp[i][1]=dp[i-1][0],dp[i][0]=dp[i-1][0]+dp[i-1][1];

//일차원 배열,dp[i] 숫자의 개수가 i인 이친수
//dp[1]=1,dp[2]=1,dp[3]=2,dp[4]=3
//(1) (10) (100,101) (1000,1001,1010)
//dp[i]=dp[i-1]+dp[i-2]
//why? 앞에 1이오면 뒤에 01,00이 오고 앞에 0이오면 1,0이 온다.?
/* dp[1][0]=0,dp[1][1]=1,dp[2][1]=0,dp[2][0]=1;
	for(int i=3;i<=N;i++){
		dp[i][1]=dp[i-1][0];
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
	}
*/
	dp[1]=1,dp[2]=1,dp[3]=2;
	
	for(int i=3;i<=N;i++){
		dp[i]=dp[i-1]+dp[i-2];
	} 
	cout<<dp[N];
	return 0; 
}
