#include<bits/stdc++.h>
using namespace std;

int n,mdist=0,midx;
vector<pair<int,int> > v[100001];
bool visited[100002]={0,};

void dfs(int node,int dist){
	if(visited[node]) return;
	if(dist>mdist){
		mdist=dist;
		midx=node;
	}
	visited[node]=true;
	for(int i=0;i<v[node].size();i++)
		dfs(v[node][i].first,v[node][i].second+dist);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int node;cin>>node;
		while(true){
			int next,w; cin>>next;
			if(next==-1) break;
			else{
				cin>>w;
				v[node].push_back({next,w});
				v[next].push_back({node,w});
			}
		}
	}
	dfs(1,0);
	fill(visited,visited+n+1,0);
	mdist=0;
	dfs(midx,0);
	cout<<mdist;
}
