#include<bits/stdc++.h>
using namespace std;

int comb(int n, int r){
	int p=1,q=1;
	while(r){
		p*=n--; q*=r--;
	}
	return p/q;
}

int main(){
	int n,m,k; cin>>n>>m>>k;
	double p=0;
	for(;k<=m;++k){
		p+=(double)comb(m,k)*comb(n-m,m-k)/comb(n,m);
	}
	cout<<fixed;cout.precision(9);
	cout<<p;
}
