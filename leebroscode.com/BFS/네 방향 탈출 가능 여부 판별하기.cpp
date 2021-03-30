#include<bits/stdc++.h>
using namespace std;

int n,m,board[101][101];
bool visited[101][101];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>board[i][j];
	
	bool ans=false;
	queue<pair<int,int> > Q;
	Q.push({0,0});
	visited[0][0]=true;
	
	while(!Q.empty()){
		auto cur=Q.front();Q.pop();
		int cx=cur.first,cy=cur.second;
		if(cx==n-1&&cy==m-1){
			ans=true;
			break;
		}
		for(int dir=0;dir<4;dir++){
			int nx=cx+dx[dir],ny=cy+dy[dir];
			if(nx<0||nx>=n||ny<0||ny>=m) continue;
			if(board[nx][ny]==0) continue;
			if(visited[nx][ny]) continue;
			
			Q.push({nx,ny});
			visited[nx][ny]=true;
		}
	}
	cout<<ans;
}
