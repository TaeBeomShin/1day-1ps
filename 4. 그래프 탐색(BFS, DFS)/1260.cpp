#include<bits/stdc++.h>
using namespace std;
/*
�⺻ dfs/bfs

- ������ �� : bfs�� queue�� push�ϱ� ���� �湮 ǥ��
			: dfs�� ��͸� ������ ����, ������ ��, ��͸� ���� �κ� ���� ������ �ۼ�. 
*/
int n,m,s;
vector <int> v[1001];
bool visited[1001]={0,};

void dfs(int cur){
	if(visited[cur]) return;
	cout<<cur<<" ";
	visited[cur]=true;
	for(int i=0;i<v[cur].size();i++){
		if(visited[v[cur][i]]) continue;
		dfs(v[cur][i]);
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	
	dfs(s);
	fill(visited,visited+n+1,0);
	puts("");
	queue<int> Q;
	visited[s]=true;
	Q.push(s);
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		cout<<cur<<" ";
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i];
			if(visited[next]) continue;
			visited[next]=true;
			Q.push(next);
		}
	}
}
