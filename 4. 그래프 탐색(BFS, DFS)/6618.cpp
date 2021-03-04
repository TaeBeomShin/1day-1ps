#include<bits/stdc++.h>
using namespace std;

// sol1) BFS로 모든 점 순회. 
 
vector<int> adj[20001];
int dist[20001]={0,};
int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int s,e;cin>>s>>e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	
	queue<int> Q;
	Q.push(1);
	dist[1]=0;
	
	int maxnum=0;
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		int d=dist[cur];
		for(int i=0;i<adj[cur].size();i++){
			int next=adj[cur][i];
			if(next==1) continue;
			if(dist[next]>0) continue;
			Q.push(next);
			dist[next]=d+1;
			maxnum=max(maxnum,dist[next]);
		}
	}
	
	int ans,count=0;
	for(int i=1;i<=n;i++){
		if(dist[i]==maxnum){
			if(count==0) ans=i;
			count++;	
		} 
	}
	cout<<ans<<" "<<maxnum<<" "<<count;
} 
