//간선리스트를 이용한 dfs와 bfs
//간선리스트 : 해당 노드에 연결되어있는 간선을 저장한 리스트
//간선리스트로는 bfs만 수행가능하다.
 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct Edge{
	int from,to;
}; 
Edge edge[20001]; //간선 리스트를 만들배열.
int cnt[1001];
bool check[1001];

bool cmp(const Edge &u,const Edge &v){//edge를 비교할 배열, 시작점을 기준으로 정렬한다. 
	if(u.from ==v.from){
		return u.to <v.to;
	}else{
		return u.from <v.from;
	}
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	check[start]=true;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=cnt[node]-1;i<cnt[node];i++){
			int next=edge[i].to;
			if(check[next]==false){
				check[next]=true;
				q.push(next);
			}
		}
	}
}

int main(){
	int n,m,start;
	cin>>n>>m>>start;
	for(int i=0;i<m;i++){
		cin>>edge[i].from>>edge[i].to;
		edge[i+m].from=edge[i].to;
		edge[i+m].to=edge[i].from;
	}
	m*=2;
	sort(edge,edge+m,cmp);
	for(int i=0;i<m;i++) cnt[edge[i].from]+=1;
	for(int i=1;i<n;i++) cnt[i]+=cnt[i-1];
	
	bfs(start);
	cout<<"\n";
	memset(check,false,sizeof(check));
	bfs(start);
	cout<<"\n";
	return 0;
} 	
