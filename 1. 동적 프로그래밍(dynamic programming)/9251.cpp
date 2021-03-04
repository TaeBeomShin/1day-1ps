#include<bits/stdc++.h>
using namespace std;

/*
	BOJ 9251 - LCS (dp, lcs)
	
	dp[i][j] : ���ڿ� A�� i��° �ε��� ���� ���ڿ� B�� j���� ���캼��
	���� �� �κй��ڿ��� ����.
	
	dp[i][j]=(a[i-1]==b[j-1])?dp[i][j-1]+1:max(dp[i-1][j],dp[i][j-1])
	
*/
int dp[1001][1001]; 
int main(){
	string a,b;cin>>a>>b;

	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[a.length()][b.length()];
}
