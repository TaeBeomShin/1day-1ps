#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	vector<pair<int,int> > v(n);
	for(int i=0;i<m;i++){
		int a,b,c; cin>>a>>b>>c;
		v[a-1].push_back({b-1,c});
	}
	int start,end;cin>>start>>end;
	start-=1;end-=1;
	int dist[n];
	fill(dist,dist+n,1e9);
	bool visited[n]={0};
	priority_queue<pair<int,int> >,vector<pair<int,int> >,greater<pair<int,int> >PQ;
	
	dist[start]=0;
	PQ.push({0,start});
	while(!PQ.empty()){
		int curr;
		do{
			curr=PQ.top().second;
			PQ.pop();
		}while(!PQ.empty()&&visited[curr]);
		if(visited[curr]) break;
		
		visited[curr]=true;
		for(auto &p: v[curr]){
			int next=p.first,d=p.second;
			if(dist[next]>dist[curr]+d){
				dist[next]=dist[curr]+d;
				PQ.push({dist[next],next});
			}
		}
	}
	cout<<dist[end];
}
