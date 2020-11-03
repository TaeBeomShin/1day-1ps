#include<iostream>
using namespace std;

int main(){
	int N,K;
	long long dp[201][201]={0,};
	//0부터 N까지의 정수 K개를 더해서 합이 N이 되는 경우의수
//dp[i][j]로 접근? d[i]로 접근?
//dp[i][j] 숫자를 j개 사용해서 합이 i가 되는 경우의 수. 
//dp[i][j]=dp[i-1][j-1]+dp[i-2][j-1]+ ...dp[1][j-1];으로 생각해볼수 있음. 
	cin>>N>>K;
	for(int i=0;i<=N;i++){
		dp[i][1]=1;
		dp[i][0]=0; 
	}
	
	for(int i=0;i<=N;i++){
		for(int j=2;j<=K;j++){
			for(int k=0;k<=i;k++){
				dp[i][j]+=dp[i-k][j-1]%1000000000;
			}
		}
	}

	/* 예시
	j가 개수, i가 숫장를 의미함. 
	dp[20][2]=dp[19][1]+dp[18][1].....dp[1][1]
	dp[1][2]=dp[0][1]+dp[1][1] 0+1 1+0
	0,20 1,19 2,18 ... 19,1 20,0
	*/
	cout<<dp[N][K]%1000000000;
	return 0;
}
