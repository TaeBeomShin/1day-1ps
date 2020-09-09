//��������Ʈ�� �̿��� dfs�� bfs
//��������Ʈ : �ش� ��忡 ����Ǿ��ִ� ������ ������ ����Ʈ
//��������Ʈ�δ� bfs�� ���డ���ϴ�.
 
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

typedef struct Edge{
	int from,to;
}; 
Edge edge[20001]; //���� ����Ʈ�� ����迭.
int cnt[1001];
bool check[1001];

bool cmp(const Edge &u,const Edge &v){//edge�� ���� �迭, �������� �������� �����Ѵ�. 
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
