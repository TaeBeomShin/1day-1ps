#include<bits/stdc++.h>
using namespace std;

int n,ans=0;
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int board[101][101];
bool visited[101][101];

int dfs(int x,int y,int num){
	
	visited[x][y]=true;
	ans++;
	
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(visited[nx][ny]) continue;
		if(board[nx][ny]!=num) continue;
		dfs(nx,ny,num);
	}
	
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
	
	int cnt=0,num=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]) continue;
			dfs(i,j,board[i][j]);
			if(ans>=4) cnt++;
			num=max(num,ans);
			ans=0;
		}
	}
	cout<<cnt<<" "<<num<<"\n";
}
