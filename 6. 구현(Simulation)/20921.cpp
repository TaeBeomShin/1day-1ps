#include<bits/stdc++.h>
using namespace std;
// BOJ 17432를 단순화한 문제. 
int main(){
	int n,k;cin>>n>>k;
	
	bool visited[n+1]={false,};
	
	for(int i=n-1;i>=0;i--){
		if(k>=i){
			k-=i;
			cout<<i+1<<" ";
			visited[i+1]=true;
		}
	}
	for(int i=1;i<=n;i++) if(!visited[i]) cout<<i<<" ";
	cout<<"\n";
}
