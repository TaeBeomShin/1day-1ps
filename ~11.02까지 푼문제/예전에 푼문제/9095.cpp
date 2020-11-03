#include<iostream>

using namespace std;

int main(){
//숫자가 놓이는 순서가 다르면 다른것으로 취급함.
//dp[1]=1 dp[2]=1+1,2 dp[3]=1+1+1,1+2,2+1,3
//dp[i]=dp[i-1]+dp[i-2]+dp[i-3]
	int t,n;
	int dp[11]={0,1,2,4,};
	for(int i=4;i<=11;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}
