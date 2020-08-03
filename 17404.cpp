#include<iostream>

using namespace std;

int min(int a,int b){
	return (a>=b)?b:a;
}
int main(){
	//RGB거리와 다른점, 양끝값
	//양끝값에 대해서만 한번더 생각.
	//젤 처음 고른 값을 알아야함!
	//처음 값 고르자 마자 N번재 색깔에 대한 경우도 결정하는 것이 좋음.
	 
	
	int N;
	cin>>N;
	int rgb[N+1][3]={0,};
	int dp[N+1][3]={0,};
	for(int i=1;i<=N;i++){
		cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
	}
	
	int ans=1000*1000+1;
	for(int k=0;k<=2;k++){

		for(int i=0;i<=2;i++){
			if(i==k)//첫값을 고정시켜놓고 진행한다. 
				dp[1][i]=rgb[1][i];
			else
				dp[1][i]=1000*1000+1;
		}
		for(int i=2;i<=N;i++){
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+rgb[i][0];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+rgb[i][1];
			dp[i][2]=min(dp[i-1][1],dp[i-1][0])+rgb[i][2];
		}
		for(int i=0;i<=2;i++){
			if(i==k) continue;//마지막 값과 첫값이 다른 케이스만 고려. 
			ans=min(ans,dp[N][i]);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
