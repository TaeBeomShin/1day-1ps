//Boj 1463번, BOj 12852(1463번 + 경로 저장하기. BFS에서도 많이 출제됨.) 
#include<bits/stdc++.h>
using namespace std;

int n,dp[1000001]={0,0,1,1,};
int nextnum[1000001];
int main(){
	cin>>n;
	for(int i=4;i<=n;i++){
		if(i%3==0&&dp[i/3]<dp[i-1]){
			dp[i]=dp[i/3]+1;
			nextnum[i]=i/3;	
		}
		else if(i%2==0&&dp[i/2]<dp[i-1]){
			dp[i]=dp[i/2]+1;
			nextnum[i]=i/2;	
		}	
		else{
			dp[i]=dp[i-1]+1;
			nextnum[i]=i-1;
		}
	}
	cout<<dp[n]<<"\n"<<n<<" ";
	while(nextnum[n]!=0){
		cout<<nextnum[n]<<" ";
		n=nextnum[n];
	}
	cout<<1;
}
