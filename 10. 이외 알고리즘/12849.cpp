#include<bits/stdc++.h>
using namespace std;

// 0: �������а�, 1:�����, 2:�̷���, 3:�ž��, 4:�Ѱ�������, 5:������, 6:�л�ȸ��, 7:�������а� 
vector<int> dp(8);
int main(){
	int d;cin>>d;
	while(d--){
		vector<int> temp(8);
		temp[0]=dp[1]+dp[2];
		temp[1]=dp[0]+dp[3]+dp[2];
		temp[2]=dp[0]+dp[1]+dp]4];
		temp[3]=dp[1]+dp[2]+dp[4]+dp[5];
		temp[4]=dp[2]+dp[3]+dp[5]+dp[7];
		temp[5]=dp[3]+dp[4]+dp[6];
		temp[6]=dp[5]+dp[7];
		temp[7]=dp[6]+dp[4];
		for(int i=0;i<8;i++) v[i]%=1000000007;
		
		dp.assgin(temp.begin(),temp.end());
		d-=1;
	} 
}
