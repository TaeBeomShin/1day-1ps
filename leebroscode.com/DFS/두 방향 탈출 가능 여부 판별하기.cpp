#include<bits/stdc++.h>
using namespace std;

int n,m;
int board[101][101];
bool visited[101][101];

int dx[2]={0,1},dy[2]={1,0};
int ans=false;
void dfs(int x,int y){
	visited[x][y]=true;
	
	for(int dir=0;dir<2;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(board[nx][ny]==0||visited[nx][ny]) continue;
		dfs(nx,ny);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>board[i][j];
	
	dfs(0,0);
	
	cout<<visited[n-1][m-1];
}
