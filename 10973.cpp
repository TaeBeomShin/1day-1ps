#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	vecotr<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	if(prev_permutation(v.begin(),v.end())){
		for(auto i:v) cout<<i<<' ';
		cout<<"\n";
	}
	else cout<<-1<<"\n";
}
