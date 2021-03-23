#include<bits/stdc++.h>
using namespace std;

int n,ans;
int board[16][16];
bool visited[16][16];

int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};

void initialVisit(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visited[i][j]=false;
		}
	}
}
void MoveCheck(int x,int y){
	visited[x][y]=true;
	for(int dir=0;dir<8;dir++){
		int nx=dx[dir],ny=dy[dir];
		
		while(x>=0&&x<n&&y>=0&&y<n){
			visited[x][y]=true;
			x+=nx;y+=ny;
		}
	}
}

void dfs(int x,int y,int cnt){
	MoveCheck(x,y);
	if(cnt==n){
		ans++;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				dfs(i,j,cnt+1);
			}
		}
	}
}
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dfs(0,0,1);
		}
	}
	cout<<ans;
}
