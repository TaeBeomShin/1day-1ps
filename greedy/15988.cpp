#include<iostream>
using namespace std;
long long dp[1000001]={0,1,2,4,};
int num[1000001];
int main(){
	int t,max=0;
	cin>>t;
	
	for(int i=0;i<t;i++){
		 cin>>num[i];
		 if(max<num[i]) max=num[i];
	}
	for(int i=4;i<=max;i++)	dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])% 1000000009;

	for(int i=0;i<t;i++) cout<<dp[num[i]]<<"\n";
}
 
