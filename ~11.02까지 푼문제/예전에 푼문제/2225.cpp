#include<iostream>
using namespace std;

int main(){
	int N,K;
	long long dp[201][201]={0,};
	//0���� N������ ���� K���� ���ؼ� ���� N�� �Ǵ� ����Ǽ�
//dp[i][j]�� ����? d[i]�� ����?
//dp[i][j] ���ڸ� j�� ����ؼ� ���� i�� �Ǵ� ����� ��. 
//dp[i][j]=dp[i-1][j-1]+dp[i-2][j-1]+ ...dp[1][j-1];���� �����غ��� ����. 
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

	/* ����
	j�� ����, i�� ���带 �ǹ���. 
	dp[20][2]=dp[19][1]+dp[18][1].....dp[1][1]
	dp[1][2]=dp[0][1]+dp[1][1] 0+1 1+0
	0,20 1,19 2,18 ... 19,1 20,0
	*/
	cout<<dp[N][K]%1000000000;
	return 0;
}
