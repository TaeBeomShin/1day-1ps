#include<bits/stdc++.h>
using namespace std;

long long dp[36]={1,};
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		long long temp=0;
		for(int j=0;j<i;j++){
			temp+=dp[j]*dp[i-j-1];
		}
		dp[i]=temp;
	}
	cout<<dp[n];
}
