#include<iostream>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

int main(){
	fastio;
	int N;
	cin>>N;
	int dp[31]={1,};
	
	for(int i=1;i<31;i+=2){
		dp[i]=0;//홀수번째는 채울수 없음.(총 면적이 짝수여야함) 
	}
	dp[2]=3,dp[4]=11;
	for(int i=4;i<31;i+=2){
		dp[i]=dp[i-2]*3;
		
		for(int j=4;i-j>=0;j+=2)
			dp[i]+=dp[i-j]*2;
	}
	
	cout<<dp[N];
	
	return 0;
}
