#include<bits/stdc++.h>
using namespace std;
int n,ans;

void dfs(int count){
	if(count>=n){
		if(count==n) ans++;
		return;
	}
	for(int i=1;i<=4;i++) dfs(count+i);
	
}
int main(){
	cin>>n;
	dfs(0);
	cout<<ans;
}
