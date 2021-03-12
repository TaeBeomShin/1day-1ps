#include<bits/stdc++.h>
using namespace std;

int n,A[20],sum=0;
map<int,int> M;

void dfs(int idx){
	if(idx==n){
		if(M.find(sum)==M.end()) M[sum]=1;
		return;	
	}
	dfs(idx+1);
	sum+=A[idx];
	dfs(idx+1);
	sum-=A[idx];
}
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>A[i];
	dfs(0);
	
	for(int i=1;i<=100000*n;i++){
		if(M.find(i)==M.end()){
			cout<<i;
			return 0;
		}
	}
}
