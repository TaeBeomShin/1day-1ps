#include<iostream>

using namespace std;

int min(int a,int b){
	return (a>=b)?b:a;
}
int main(){
	//RGB�Ÿ��� �ٸ���, �糡��
	//�糡���� ���ؼ��� �ѹ��� ����.
	//�� ó�� �� ���� �˾ƾ���!
	//ó�� �� ���� ���� N���� ���� ���� ��쵵 �����ϴ� ���� ����.
	 
	
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
			if(i==k)//ù���� �������ѳ��� �����Ѵ�. 
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
			if(i==k) continue;//������ ���� ù���� �ٸ� ���̽��� ���. 
			ans=min(ans,dp[N][i]);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
