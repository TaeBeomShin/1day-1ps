#include<bits/stdc++.h>
using namespace std;

vector <int> v[1001];
bool visited[1001];
int n,m,start;

void dfs(int index){
	visited[index]=true;
	cout<<index<<" ";
	for(int i=0;i<v[index].size();i++){
		int next=v[index][i];
		if(!visited[next]){
			dfs(next);
		}
	}
}

void bfs(int index){
	queue <int> q;
	visited[index]=true;
	q.push(index);

	while(!q.empty()){
		int node=q.front();
		cout<<node<<" ";
		q.pop();
		
		for(int i=0;i<v[node].size();i++){
			int next=v[node][i];
			if(!visited[next]){
				visited[next]=true;
				q.push(next);
			}
		}
	}
}
int main(){
	cin>>n>>m>>start;
	
	while(m--){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	
	dfs(start);
	puts(" ");
	memset(visited,false,n);
	bfs(start);
}
