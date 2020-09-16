#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool visited[2001];
vector<int> relation[2001];
int n,m; bool answer=false;

void dfs(int idx, int cnt){
	if(cnt==4){
		answer=true;
		return;
	}
	visited[idx]=true;
	for(int i=0;i<relation[idx].size();i++){
		int next=relation[idx][i];
		if(visited[next]==false){
			dfs(next,cnt+1);
		}
		if(answer) return;
	}
	visited[idx]=false;
} 
int main(){
	fastio;
	cin>>n>>m;
	while(m--){
		int p1,p2;
		cin>>p1>>p2;
		relation[p1].push_back(p2);
		relation[p2].push_back(p1);
	}
	
	for(int i=0;i<n;i++){
		memset(visited,false,sizeof(visited));
		dfs(i,0);
		if(answer) break;
	}	
	cout<<answer;

}
