#include<bits/stdc++.h>
using namespace std;

int A[1001];
int dp[1001];

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<=i;j++){
			if(A[i]<A[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	}
	
	int max=0;
	for(int i=0;i<n;i++){
		if(dp[i]>max) max=dp[i];
	}
	cout<<max;
} 
