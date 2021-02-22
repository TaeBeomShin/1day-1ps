#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	
	int path[m]={0,};
	for(int i=0;i<m;i++) cin>>path[i];

	long long psum[n+1]={0,};	
	for(int i=0;i<m-1;i++){
		if(path[i]<path[i+1]){ 
			psum[path[i]]+=1;
			psum[path[i+1]]+=-1;
		}else{
			psum[path[i+1]]+=1;
			psum[path[i]]+=-1;
		}
	}
	
	for(int i=1;i<=n;i++)
		psum[i]=psum[i]+psum[i-1];
	
	long long sum=0;
	for(int i=1;i<n;i++){
		int t,c,cp;cin>>t>>c>>cp;
		if(psum[i]!=0)
			sum+=min(t*psum[i],c*psum[i]+cp);
	}
	
	cout<<sum;
} 
