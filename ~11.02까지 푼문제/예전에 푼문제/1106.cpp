#include<bits/stdc++.h>
#define MAX 100*1000

using namespace std;

int c,n;
int dp[MAX]={0,};
int main(){
	cin>>c>>n;
	
	vector < pair<int,int> > v(n);

	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
		//first�� ���, second�� ������ ó���� �Էµ�.

	//dp[i]: i�ݾ��� �̿��� �θ��� �մ� �����. 
	for(int i=0;i<n;i++)
		for(int j=v[i].first;j<=MAX;j++)
				dp[j]=max(dp[j],dp[j-v[i].first]+v[i].second);

	for(int i=1;i<=MAX;i++){
		if(dp[i]>=c){
			cout<<i;break;
		}
	}
} 
