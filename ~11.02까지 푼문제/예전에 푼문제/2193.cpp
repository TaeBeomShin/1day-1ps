#include<iostream>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

int main(){
	fastio;
	int N;
	cin>>N;
	long long dp[91]={0,};
	
//N�ڸ� ��ģ���� ���� ���ϱ�.(bottom-up) 
//1,10,100,101,1000,1001
//ù�ڸ��� 1�̸� 0�ۿ� ����, ù�ڸ����� 0�� ����.
//������ �迭, dp[i][j] i�� ������ ���� j=0, ���ڸ��� 0, j=1, ���ڸ��� 1,
// dp[1][1]=1,dp[1][0]=0,dp[2][1]=0,dp[2][0]=1,dp[3][1]=1,dp[3][1]=1;
// dp[i][1]=dp[i-1][0],dp[i][0]=dp[i-1][0]+dp[i-1][1];

//������ �迭,dp[i] ������ ������ i�� ��ģ��
//dp[1]=1,dp[2]=1,dp[3]=2,dp[4]=3
//(1) (10) (100,101) (1000,1001,1010)
//dp[i]=dp[i-1]+dp[i-2]
//why? �տ� 1�̿��� �ڿ� 01,00�� ���� �տ� 0�̿��� 1,0�� �´�.?
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
