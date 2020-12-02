#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,p,q;
map<ll,ll> m;

ll dp(ll k){
	//해당 숫자가 있는지 확인한다, 수가 없다면 재귀를 수행한다. 
	if(m.count(k)) return m[k];
	return m[k]=dp(k/p)+dp(k/q);
}
int main(){
	m[0]=1;
	cin>>n>>p>>q;
	cout<<dp(n);
}
