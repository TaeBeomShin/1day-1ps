#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int psum[100002]={0,};
int main(){
	fastio;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		psum[i]=psum[i-1]+num;
	}
	
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int start,end;cin>>start>>end;
		cout<<psum[end]-psum[start-1]<<"\n";
	}
}
