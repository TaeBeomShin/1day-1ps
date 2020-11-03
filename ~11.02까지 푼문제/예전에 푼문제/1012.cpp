#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define X first
#define Y second
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0 ,1 ,-1 };

int main(){
	fastio;
	int t,m,n,k;
	cin>>t;

	while(t--){
		cin>>m>>n>>k;
		int board[50][50]={0,};
		
		while(k--){
			int x,y;cin>>x>>y;
			board[x][y]=1;//배추들이 심어져 있는 위치를 표시. 
		}
		
		int count=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				
				if(board[i][j]==1){
					count++;
					board[i][j]=2;
					queue < pair<int,int> > Q;
					Q.push({i,j});
					while(!Q.empty()){
						auto cur=Q.front();Q.pop();					
						for(int dir=0;dir<4;dir++){
							int nx=cur.X+dx[dir];
							int ny=cur.Y+dy[dir];
							
							if(nx<0||nx>=m||ny<0||ny>=n) continue;
							if(board[nx][ny]==1){						
								Q.push({nx,ny});
								board[nx][ny]=2;
							}
						}
					}
				}
			}
		}
		cout<<count<<"\n";
	}
}
