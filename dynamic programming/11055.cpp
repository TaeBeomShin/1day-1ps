#include<bits/stdc++.h>
using namespace std;

int A[1001]={0,};
int dp[1001]={0,};

int main(){
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	
	for(int i=1;i<=n;i++){
		dp[i]=A[i];
		for(int j=1;j<=i;j++){
			if(A[j]<A[i]) dp[i]=max(dp[i],dp[j]+A[i]);
//			1.���� �ε��� �տ��� �� ���� ���� ã�´�.
//			2.�� ���Ҹ� ��������, �� ���Ҹ� �������� ���� Ŀ������ �Ǵ��Ѵ�. ���� Ŀ���� �ʴ´ٸ� �ռ����� ������ ����� �ǹ��̴�. 
		}
	}
	
	int max=0;
	for(int i=1;i<=n;i++){
		if(dp[i]>max) max=dp[i];
	}
	cout<<max;
}

