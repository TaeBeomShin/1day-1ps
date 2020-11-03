#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0) 
using namespace std;

int n,l;
int main(){
	fastio;
	cin>>n>>l;
	vector<int> A(n),B(n);
	for(int i=0;i<n;i++) cin>>A[i];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> PQ; 

	for(int i=0;i<n;i++){
		PQ.push({A[i],i});
		while(PQ.top().second<i-l+1) PQ.pop();//최솟값은 범위 안에 있어야된다. 
		B[i]=PQ.top().first;
	}
	
	for(int i=0;i<n;i++) cout<<B[i]<<" ";	
}
