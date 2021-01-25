#include<bits/stdc++.h>
using namespace std;

// 0: 정보과학관, 1:전산관, 2:미래관, 3:신양관, 4:한경직기념관, 5:진리관, 6:학생회관, 7:형남공학관 
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
