#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

vector<int> v[1001];//간선리스트. 
bool check[1000];

void dfs(int node){
	check[node]=true;
	for(int i=0;i<v[node].size();i++){
		int next=v[node][i];
		if(check[next]==false) dfs(next);
	}	
}
int main(){
	int n,m;cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int c=0;
	for(int i=1;i<=n;i++){
		if(check[i]==false){
			dfs(i);
			c++;
		}
	}
	cout<<c;
}
