#include<bits/stdc++.h>
using namespace std;

int n,k;
int line[101][101]={0,};//line[i][j] i��° ������ j��° �۾��� �۾��ð�.
int moveto[101][101][101]={0,};//move[i][k][j] i��° ���忡�� k��° ���������� �̵��ð� j��° �۾��� ������. 
int dp[101][101]={0,};//i��° ���忡�� j��° �۾����� �ϴµ� �ɸ��ð�. 
int main(){
	cin>>n>>k;
	
	for(int j=1;j<=n;j++){
		for(int i=1;i<=k;i++) cin>>line[i][j];
		if(j==n) break;
		for(int i=1;i<=k;i++){
			for(int s=1;s<=k;s++){
				if(i==s) continue;
				cin>>moveto[i][s][j];
//				cout<<moveto[i][s][j]<<"\n";
			}	
		}
	}
	
	for(int i=1;i<=k;i++){//i~k, 1��° �۾��� ���� �ʱ�ȭ. 
		dp[i][1]=line[i][1];
	}
	 
	for(int j=2;j<=n;j++){//j��° �۾�
		for(int i=1;i<=k;i++){
			dp[i][j]=dp[i][j-1]+line[i][j];
			for(int s=1;s<=k;s++){
				if(i==s) continue;//���� �����̶�� ���ư�. 
				dp[i][j]=min(dp[i][j],dp[s][j-1]+line[i][j]+moveto[s][i][j-1]);
			}
		}
	}
	
	int ans=1e9;
	for(int i=1;i<=k;i++) ans=min(ans,dp[i][n]);
	cout<<ans;
}
