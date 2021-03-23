#include<bits/stdc++.h>
using namespace std;

int n,m;
int board[51][51];
bool visited[51][51];

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int dfs(int x,int y,int num){
	
	visited[x][y]=true;
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
		
		if(nx<0||nx>=n||ny<0||ny>=m) continue;
		if(visited[nx][ny]) continue;
		if(board[nx][ny]<=num) continue;
		
		dfs(nx,ny,num);
		
	}
}
int main(){
	cin>>n>>m;
	
	int s=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>board[i][j];	
			s=max(s,board[i][j]);
		}
	
	int ans=0,ansk=1;
	for(int k=1;k<=s;k++){
		//방문 배열 초기화 
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				visited[i][j]=0;
			}
		}
		
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(board[i][j]<=k) continue;
				if(visited[i][j]) continue;
				dfs(i,j,k);
				cnt++;
			}
		}
		if(ans<cnt){
			ans=cnt;
			ansk=k;
		}
	}
	cout<<ansk<<" "<<ans;
}
