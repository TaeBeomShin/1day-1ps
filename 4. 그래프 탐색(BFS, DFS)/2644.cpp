#include<bits/stdc++.h>
using namespace std;

int start,dest,n,m;
/**
* 최단거리, BFS 
*/
int visited[101];
vector<int> family[101];

int main(){
	cin>>n;
	cin>>start>>dest;
	cin>>m;
	
	for(int i=0;i<m;i++){
		int parent,kid;cin>>parent>>kid;
		family[parent].push_back(kid);
		family[kid].push_back(parent);
	}
	
	int ans=-1;
	queue<pair<int,int> > Q;
	Q.push({start,0});
	visited[start]=true;
	
	while(!Q.empty()){
		int cur=Q.front().first;
		int curValue=Q.front().second;
		visited[cur]=true;
		Q.pop();

		if(cur==dest){
			ans=curValue;
			break;
		}
		for(int i=0;i<family[cur].size();i++){
			int next=family[cur][i];
			if(visited[next]){
				continue;
			}else{
				Q.push({next,curValue+1});
			}
			
		}
	}
	cout<<ans;
} 
