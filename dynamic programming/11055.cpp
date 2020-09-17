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
//			1.현재 인덱스 앞에서 더 작은 값을 찾는다.
//			2.그 원소를 더했을때, 앞 원소를 더했을때 보다 커지는지 판단한다. 만약 커지지 않는다면 앞수보다 더작은 수라는 의미이다. 
		}
	}
	
	int max=0;
	for(int i=1;i<=n;i++){
		if(dp[i]>max) max=dp[i];
	}
	cout<<max;
}

