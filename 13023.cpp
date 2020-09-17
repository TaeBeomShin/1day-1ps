#include<bits/stdc++.h>
using namespace std;

vector <int> v[2001];
bool visited[2001];
bool answer=false;

void dfs(int index,int count){
	if(count==4){
		answer=true;
		return;
	}
	
	visited[index]=true;
	for(int i=0;i<v[index].size();i++){
		int next=v[index][i];
		if(!visited[next]){
			visited[next]=true;
			dfs(next,count+1);
			if(answer) break;
		}
	}
	visited[index]=false;
}
int main(){
	int n,m; cin>>n>>m;
	
	while(m--){
		int a,b;cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		memset(visited,false,n);
		dfs(i,0);
		if(answer) break;
	}
	
	cout<<answer;
}

