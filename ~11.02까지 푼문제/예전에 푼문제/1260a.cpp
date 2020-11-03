//인접 리스트 이용.
//인접 리스트 A[i] 에는 i와 연결된 정점을 리스트로 원소를 가진다.
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

vector<int> a[1001];//인접리스트 배열. 
bool check[1001];//방문체크하는 배열. 

//dfs는 인접리스트를 이용하여 재귀적으로 구현. 
void dfs(int node){
	check[node]=true;
	cout<<node<<" ";
	for(int i=0;i<a[node].size();i++){
		int next=a[node][i];//node와 연결된 i번째 정점. 
		if(check[next]==false) dfs(next);//방문하지 않은 정점에 대해 dfs 수행함.
		//인접리스트로 구현했기때문에, 재귀적으로 종료조건을 표현안해도됨. 
	}
}

//bfs는 큐자료형을 이용하여서 구현함. bfs는 단계별로 수행된다. 
void bfs(int start){
	queue<int> q;
	memset(check,false,sizeof(check));
	check[start]=true;
	q.push(start);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=0;i<a[node].size();i++){
			int next=a[node][i];
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
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);// 인접리스트 a의 u번째 리스트에 v를 삽입. 
		a[v].push_back(u);// 인접리스트 a의 v번째 리스트에 u를 삽입. 
	}
	for(int i=1;i<=n;i++) sort(a[i].begin(),a[i].end());//빠르게 수행하기 위해, 시작정점 기준으로 정렬을 수행한다. 
	
	dfs(start);
	puts(" ");
	bfs(start);

	return 0;
}
