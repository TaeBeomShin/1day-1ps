#include<bits/stdc++.h>
#define INF 1e9
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

//간선리스트와 거리배열 선언. 
vector<pait<int,int> > graph[20001];
int d[100001];
//다익스트라 알고리즘으로 순회한다. 
void dijkstra(int start){//시작점을 원소로 받음. 
	priority_queue<pair<int,int> > pq;//우선순위 큐, 이후동작 방식은 bfs와 유사. 
	pq.push({0,start});
	d[start]=0;//자기자신이므로 당연히 거리는 0. 
	while(!pq.empty()){// 우선순위 큐에 저장된 내용 불러옴 가중치와 정점으로 저장되어 있음. 
		int dist=-pq.top().first;
		int now=pq.top().second;
		pq.pop();
		if(d[now]<dist) continue;
		for(int i=0;i<graph[now].size();i++){
			int cost=dist+graph[now][i].second;
			if(cost<d[graph[now][i].first]){
				d[graph[now][i].first]=cost;
				pq.push(make_pair(-cost,graph[now][i].first));
			}
		}
	}
}
int main(){
	fastio;
	int v,e;cin>>v>>e;
	int start;cin>>start;
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
	}
	fill(d,d+100001,INF);
	
	dijkstra(start);
	
	for(int i=1;i<=v;i++){
		if(d[i]==INF){
			cout<<"INF"<<"\n";
		}else{
			cout<<d[i]<<"\n";
		}
	}
}
