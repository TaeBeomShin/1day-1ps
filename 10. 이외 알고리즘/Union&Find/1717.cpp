#include<bits/stdc++.h>
using namespace std;

int num[1000001];
int find(int n){
	if(n==num[n]) return n;
	else return num[n]=find(num[n]);
}

void u(int a,int b){
	int aroot=find(a);
	int broot=find(b);
	num[aroot]=broot;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int n,m;cin>>n>>m;
	for(int i=0;i<=n;i++) num[i]=i;
	
	for(int i=0;i<m;j++){
		int t,a,b;
		cin>>t>>a>>b;
		if(t==0){
			u(a,b);
		}else{
			if(find(a)==find(b)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	} 
}
