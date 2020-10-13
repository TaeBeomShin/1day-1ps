#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	int n;cin>>n;
	fastio;
	priority_queue<int,vector<int>,greater<int>> pq;
	
	while(n--){
		int x;cin>>x;
		if(pq.empty()&&x==0) cout<<"0\n";
		else{
			if(x>0) pq.push(x);
			else if(x==0){
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
	}
}
