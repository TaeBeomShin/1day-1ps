#include<bits/stdc++.h>
using namespace std;

vector<int> v[101];
bool visited[101];

int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	int count=0;
	queue<int> Q;
	Q.push(1);
	visited[1]=true;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		count++;
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i];
			if(visited[next]) continue;
			Q.push(next);
			visited[next]=true;
		}
	}
	
	cout<<count-1;
}
