#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
unordered_map <ll,ll> m;
ll n,p,q,x,y;

ll dp(ll k){
	if(m.count(k)) return m[k];
	else if(k<=0) return 1;
	return m[k]=dp(k/p-x)+dp(k/q-y);
}
int main(){
	m[0]=1;
	cin>>n>>p>>q>>x>>y;
	cout<<dp(n);
}
