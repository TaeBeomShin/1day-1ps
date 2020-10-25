#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	priority_queue <int,vector<int>,greater<int>> PQ;
	
	int num;
	for(int i=0;i<n;i++){
		cin>>num;
		PQ.push(num);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>num;
			PQ.push(num);
		}
		while(PQ.size()!=n){
			PQ.pop();
		}
	}
	cout<<PQ.top();
} 
