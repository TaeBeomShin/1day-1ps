#include<iostream>
#define mod 1000000007
using namespace std;

long long dp[1001]={1,};
int main(){
	int n;
	cin>>n;
	//3X2 Ÿ���� ä��� ����Ǽ� : 3����, 4Ÿ���� 2ĭ �������鼭 ���ο� ����� ���� �����.
	
	for(int i=1;i<=n;i+=2) dp[i]=0;
	 
	dp[2]=3;
	
	for(int i=4;i<=n;i+=2){
		dp[i]=dp[i-2]*3;
		
		for(int j=4;i-j>=0;j+=2) dp[i]+=dp[i-j]*2;
		dp[i]=dp[i]%1000000007;
	}
	
	cout<<dp[n];
}
