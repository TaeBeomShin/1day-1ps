#include<bits/stdc++.h>
using namespace std;

int n,m;
bool check[2001];
vector <int > v[2001];
bool answer=false;
void dfs(int index,int count){
	if(count==4){
		answer=true;
		return;
	}
	check[index]=true;
	for(int i=0;i<v[index].size();i++){
		int next=v[index][i];
		if(check[next]==false) dfs(next,count+1);
		if(answer) return;
	}
	check[index]=false;
}
int main(){
	cin>>n>>m;
	while(m--){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		memset(check,false,n);
		dfs(i,0);
		if(answer) break;
	}
	cout<<answer;
}
