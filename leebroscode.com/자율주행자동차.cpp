#include<bits/stdc++.h>
using namespace std;

int board[50][50];
bool visited[50][50];
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int rx[4]={0,-1,0,1},ry[4]={1,0,-1,0};
int main(){
	int n,m;cin>>n>>m;
	int x,y,d;cin>>x>>y>>d;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>board[i][j];
	
	queue<pair<int,int> > Q;
	Q.push({y-1,x-1});
	visited[y-1][x-1]=true;
	
	while(!Q.empty()){
		auto cur=Q.front();Q.pop();
		int cx=cur.second,cy=cur.first;
		visited[cy][cx]=true;
		
		cout<<cy<<" "<<cx<<"\n";
		bool check=true;
		for(int i=0;i<4;i++){
			d++;
			if(d>=4) d=0;
			int nx=cx+dx[d],ny=cy+dy[d];
			//방문할 수 없는 경우. 
			if(nx<0||nx>=m||ny<0||ny>=n) continue;
			if(visited[ny][nx]) continue;
			if(board[ny][nx]==1) continue;
			//방문할 수 있는 경우.
			Q.push({ny,nx});
			check=false;
		}
		
		//4방향 확인했으나 전진 못한 경우. 
		bool flag=false;
		if(check){
			int nx=cx+rx[d],ny=cy+ry[4];
			if(board[ny][nx]==1){
				flag=true;
				break;
			}else{
				Q.push({ny,nx});
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(visited[i][j]) ans++;
	
	cout<<ans;
}
