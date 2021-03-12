#include<bits/stdc++.h>
using namespace std;

int N;
void dfs(int sum,int sign,int num,int n,string str){
	if(n==N){
		sum+=(num*sign);
		if(sum==0) cout<<str<<"\n";
		return;
	}
	dfs(sum,sign,num*10+(n+1),n+1,str+' '+char(n+1+'0'));
	dfs(sum+(sign*num),1,n+1,n+1,str+'+'+char(n+1+'0'));
	dfs(sum+(sign*num),-1,n+1,n+1,str+'-'+char(n+1+'0'));
}

int main(){
	int t;cin>>t;
	while(t--){
		cin>>N;
		dfs(0,1,1,1,"1");
		puts("");
	}
}
