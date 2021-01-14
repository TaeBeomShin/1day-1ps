#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n,m;cin>>n>>m;
	vector<int> A(n+m);
	for(int i=0;i<n+m;i++) cin>>A[i];
	sort(A.begin(),A.end());
	
	for(int num : A) cout<<num<<" ";
} 
