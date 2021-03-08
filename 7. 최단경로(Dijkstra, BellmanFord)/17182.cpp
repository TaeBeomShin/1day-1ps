#include<bits/stdc++.h>
using namespace std;
/*
	BOJ17182 - DFS + 플로이드와샬 
*/
int dist[10][10];
int visited[10];
int n,k,ans=1e9;

void dfs(int idx,int result,int cnt){
	//종료조건
	if(cnt==n){
		ans=min(ans,result);
		return;
	}
	
	for(int i=0;i<n;i++){
		if(visited[i]) continue;
		visited[i]=true;
		dfs(i,result+dist[idx][i],cnt+1);
		visited[i]=false;
	} 
}
int main(){
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dist[i][j];
		}
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j){
					dist[i][j]=1e9;
					continue;
				}
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	visited[k]=true;
	dfs(k,0,1);
	
	cout<<ans;
}
