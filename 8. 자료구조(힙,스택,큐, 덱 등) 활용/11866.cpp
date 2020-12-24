#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n,k;cin>>n>>k;
	queue <int> Q;
	for(int i=1;i<=n;i++) Q.push(i);
	
	cout<<"<";
	while(!Q.empty()){
		int count=1;
		for(int i=0;i<k-1;i++){
			Q.push(Q.front());
			Q.pop();
		}
		if(Q.size()!=1) cout<<Q.front()<<", ";
		else cout<<Q.front();
		Q.pop();
	}
	cout<<">";
}
