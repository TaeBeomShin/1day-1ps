#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,p,q;
map<ll,ll> m;

ll dp(ll k){
	//�ش� ���ڰ� �ִ��� Ȯ���Ѵ�, ���� ���ٸ� ��͸� �����Ѵ�. 
	if(m.count(k)) return m[k];
	return m[k]=dp(k/p)+dp(k/q);
}
int main(){
	m[0]=1;
	cin>>n>>p>>q;
	cout<<dp(n);
}
