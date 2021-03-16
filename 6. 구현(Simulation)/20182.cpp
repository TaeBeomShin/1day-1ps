#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;

vector<int> adj[11];
int dist[11][11],new_dist[11][11];
bool visited[11];
int minn=1e9;

void dfs(int idx,int result,int ans){
//	cout<<idx<<" "<<result<<" "<<ans<<" "<<"check\n";
	if(idx==b){
		if(result<=c) minn=min(ans,minn);
		return;
	}
	
	//연결되어있는 정점으로 이동한다. 
	for(int i=0;i<adj[idx].size();i++){
		int next=adj[idx][i];
		if(visited[next]) continue;
//		cout<<idx<<" "<<next<<"\n";
		ans=max(ans,dist[idx][next]);
		
		visited[next]=true;
		dfs(next,result+dist[idx][next],ans);
		visited[next]=false;
	}
}
int main(){
	cin>>n>>m>>a>>b>>c;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=1e9;
			new_dist[i][j]=1e9;
		}
	}
	for(int i=0;i<m;i++){
		int s,e,cost;cin>>s>>e>>cost;
		adj[s].push_back(e);
		adj[e].push_back(s);
		dist[s][e]=cost;
		dist[e][s]=cost;
		new_dist[s][e]=cost;
		new_dist[e][s]=cost;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				new_dist[i][j]=min(new_dist[i][j],new_dist[i][k]+new_dist[k][j]);
			}
		}
	}
	
	if(new_dist[a][b]<=c){
		dfs(a,0,0);
		cout<<minn;
	}else{
		cout<<-1;
	}
} 
