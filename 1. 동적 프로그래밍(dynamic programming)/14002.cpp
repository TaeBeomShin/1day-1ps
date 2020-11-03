#include<bits/stdc++.h>
using namespace std;

int A[1001],V[1001],dp[1001];
vector<int> answer;

void go(int index){
	if(index==0) return;
	answer.push_back(A[index]);
	go(V[index]);
}
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>A[i];
	
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<=i;j++){
			if(A[i]>A[j]&&dp[j]>=dp[i]){
				dp[i]=max(dp[i],dp[j]+1);
				V[i]=j;
			}
		}
	}

	int max=0;int index=0;
	for(int i=1;i<=n;i++){
		if(max<dp[i]){
			max=dp[i];
			index=i;
		}
	}
	go(index);
	cout<<max<<"\n";
	for(int i=answer.size()-1;i>=0;i--) cout<<answer[i]<<" ";
}
