#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int ans=0;
void dfs(int x){
	
	visited[x]=true;
	
	for(int i=0;i<adj[x].size();i++){
		int next=adj[x][i];
		if(visited[next]) continue;
		dfs(next);
	}
}
int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int s,e;cin>>s>>e;
		s--;e--;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	
	dfs(0);
	
	for(int i=0;i<n;i++){
		if(visited[i]) ans++;
	}
	cout<<ans-1;
}
