#include<bits/stdc++.h>
#define INF 1e9
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

//��������Ʈ�� �Ÿ��迭 ����. 
vector<pait<int,int> > graph[20001];
int d[100001];
//���ͽ�Ʈ�� �˰������� ��ȸ�Ѵ�. 
void dijkstra(int start){//�������� ���ҷ� ����. 
	priority_queue<pair<int,int> > pq;//�켱���� ť, ���ĵ��� ����� bfs�� ����. 
	pq.push({0,start});
	d[start]=0;//�ڱ��ڽ��̹Ƿ� �翬�� �Ÿ��� 0. 
	while(!pq.empty()){// �켱���� ť�� ����� ���� �ҷ��� ����ġ�� �������� ����Ǿ� ����. 
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
