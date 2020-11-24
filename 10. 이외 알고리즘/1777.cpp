#include<bits/stdc++.h>
#include<ext/rope>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

int main(){
	fastio;
	int n;cin>>n;
	rope<int> r;
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		r.insert(r.size()-m,i);
	}
	for(auto i:r) cout<<i<<' ';
}
