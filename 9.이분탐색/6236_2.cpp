#include<bits/stdc++.h>
using namespace std;

const int INF=int(1e9);
int n,m;
vector<int> v;

bool check(int k){
	int cnt=0,cur=0;
	for(int i=0;i<n;i++){
		if(cur<v[i]) cnt++,cur=k;
		if(cur<v[i]) return 0;
		cur-=v[i];
	}
	return cnt<=m;
}

int main(){
	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int l=0,r=INF;
	while(l+1<r){
		int m=l+r>>1;
		if(!check(m)) l=m;
		else r=m;
	}
	cout<<r;
}
