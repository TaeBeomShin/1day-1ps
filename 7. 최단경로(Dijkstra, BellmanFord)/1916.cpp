#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std; 

int main(){
	int n,m;cin>>n>>m;
	vector<P> adj[n+1];
	int dist[n+1]={0,};
	fill(dist,dist+n+1,1e9);
	bool visited[n+1]={0,};
	for(int i=0;i<m;i++){
		int curr,next,d;cin>>curr>>next>>d;
		adj[curr].push_back({next,d});
	}
	int start,end;cin>>start>>end;
	priority_queue<P,vector<P>,greater<P>> PQ;
	dist[start]=0;
	PQ.push({0,start});
	
	while(!PQ.empty()){
		int curr;
		do{
			curr=PQ.top().second;PQ.pop();
		}while(!PQ.empty()&&visited[curr]);
		if(visited[curr]) continue;
		visited[curr]=true;
		
		for(auto &p:adj[curr]){
			int next=p.first,d=p.second;
			if(dist[next]>dist[curr]+d){
				dist[next]=dist[curr]+d;
				PQ.push({dist[next],next});
			}
		}
	}
	cout<<dist[end];
}
