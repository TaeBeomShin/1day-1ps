#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define X first
#define Y second //pair에서 first,seoncd를 줄여서 쓰기위해 사용. 
using namespace std;

int board[501][501];//1이 파란칸, 0이 빨간칸에 대응. 
bool visited[501][501];//해당칸을 방문했는지 저장. 
int n,m; 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};//상우좌우 네방향. 

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>board[i][j];
	
	int mx=0;//면적의 최대값 
	int count=0;//그림의 수. 
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j] or board[i][j]==0) continue;//시작점 설정, 방문하지 않았고, 1로 색칠되어있다.
			count++;
			queue <pair<int,int> > Q;//큐에 넣고나서 방문표시. 
			visited[i][j]=true;
			Q.push({i,j});
			int paint=0;
			
			while(!Q.empty()){
				paint++;
				auto cur=Q.front();Q.pop();
				
				for(int dir=0;dir<4;dir++){
					int nx=cur.X+dx[dir];
					int ny=cur.Y+dy[dir];
					if(nx<0||nx>=n||ny<0||ny>=m) continue;
					
					if(visited[nx][ny]||board[nx][ny]!=1) continue;
					
					
					Q.push({nx,ny});
					visited[nx][ny]=true;
					
				}
			}
			mx=max(mx,paint);
			
		}
	}
	
	cout<<count<<"\n"<<mx;
	
}
