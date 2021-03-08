#include<bits/stdc++.h>
using namespace std;
/*
	BOJ11437 (BFS ����)
	
	1. �� ������ depth�� ���Ѵ�.
	2. �־��� �� ��忡�� parents�� �Ž��� �ö󰡸� LCA�� ���Ѵ�. 
*/
int parents[50001],depth[50001];
vector<int> adj[50001];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> Q;
	Q.push(1);
	depth[1]=1;

	//������ ���̸� �����Ѵ�. 
	while(!Q.empty()){

		int cur=Q.front();Q.pop();
		
		for(int i=0;i<adj[cur].size();i++){
			int next=adj[cur][i];
			if(depth[next]>0) continue;
			Q.push(next);
			depth[next]=depth[cur]+1;
			parents[next]=cur;
		}
	}
		
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		
		if(depth[a]<depth[b]) swap(a,b);
		
		while(depth[a]!=depth[b]) a=parents[a];

		while(a!=b){
			a=parents[a];
			b=parents[b];
		}
		cout<<a<<"\n";	
	}
}
	
