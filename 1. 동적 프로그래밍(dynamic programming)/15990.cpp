#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int D = 1000000009;
using namespace std;

long long dp[100001][4]={0,};
int main(){
	fastio;
	int t;cin>>t;
	
	//dp[i]= i�� 1,2,3���� ��Ÿ���� ����Ǽ�
	//���� ��ġ�� �ٸ��� �ٸ� ������� �����, ���� ���� �ι� ���� ����ϸ� �ȵ�(���� ���� ��� �ؾ���.) 
	//3= 1+2, 2+1, 3 2= 2, 1=1
	//4= 1+2+1, 1+3,3+1
	//dp[4][1]=dp[3][2]+dp[3][3], dp[4][2]=dp[2][1]+dp[2][3], dp[4][3]=dp[1][1]+dp[1][2];
	
	dp[1][1]=1;dp[2][2]=1;
	dp[3][1]=dp[3][2]=dp[3][3]=1;
	
	for(int i=4;i<=100000;i++){
		dp[i][1]=(dp[i-1][2]+dp[i-1][3])%D;
		dp[i][2]=(dp[i-2][1]+dp[i-2][3])%D;
		dp[i][3]=(dp[i-3][1]+dp[i-3][2])%D;
	}
	
	while(t--){
		int num;cin>>num;
		cout<<(dp[num][1]+dp[num][2]+dp[num][3])%D<<"\n";
	}
}
