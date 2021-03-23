#include<bits/stdc++.h>
using namespace std;

int board[25][25];
bool visited[25][25];
vector<int> v;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int n,ans=0;

void dfs(int x,int y){
	
	visited[x][y]=true;
	ans++;
	
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir],ny=y+dy[dir];
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(board[nx][ny]==0) continue;
		if(visited[nx][ny]) continue;
		dfs(nx,ny);
	}	
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
	
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]==0) continue;
			if(visited[i][j]) continue;
			dfs(i,j);
			cnt++;
			v.push_back(ans);
			ans=0;
		}
	}
	
	cout<<cnt<<"\n";
	sort(v.begin(),v.end());
	for(int num:v) cout<<num<<"\n";
	
}
