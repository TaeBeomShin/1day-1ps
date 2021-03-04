#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;

// sol2) 거리가 1인 다익스트라. 
 
vector<int> adj[20001];
int dist[20001]={0,};

int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int s,e;cin>>s>>e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	
	priority_queue<P,vector<P>,greater<P>> PQ;
	PQ.push({0,1});
	
	for(int i=2;i<=n;i++)	dist[i]=1e9;
	
	while(!PQ.empty()){
		int cost=PQ.top().first,node=PQ.top().second;
		PQ.pop();
		
		if(dist[node]<cost) continue;
		
		for(int i=0;i<adj[node].size();i++){
			int nextNode=adj[node][i];
			int nextCost=cost+1;
			
			if(dist[nextNode]>nextCost){
				dist[nextNode]=nextCost;
				PQ.push({nextCost,nextNode});
			}
		}
	}
	
	int result=1,cnt=1;
	
	for(int i=2;i<=n;i++){
		if(dist[result]<dist[i]){
			cnt=1;result=i;
		}else if(dist[result]==dist[i]) cnt++;
	}
	
	cout<<result<<" "<<dist[result]<<" "<<cnt;
}
