#include<bits/stdc++.h>
using namespace std;

//영역이 주어졌을 때 적록색약인 사람과 아닌사람이 보는 구역의수
// -> 연결요소의 개수!!

int n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char board[100][100],board2[100][100];
bool visited[100][100];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]=='G') board2[i][j]='R';
			else board2[i][j]=board[i][j];
		}
	}
	
	//1. 적록색약이 아닌 사람이 BFS 수행.
	queue<pair<int,int> > Q;
	int cnt =0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]) continue;
			cnt++;
			Q.push({i,j});
			visited[i][j]=true;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();
				int cx=cur.first,cy=cur.second;
				char cv=board[cx][cy];
				
				for(int dir=0;dir<4;dir++){
					int nx=cx+dx[dir],ny=cy+dy[dir];
					if(nx<0||nx>=n||ny<0||ny>=n) continue;
					if(visited[nx][ny]) continue;
					if(cv!=board[nx][ny]) continue;
					
					Q.push({nx,ny});
					visited[nx][ny]=true;	
				}
			}
		}
	}
	
	int cnt2 =0;
	
	for(int i=0;i<n;i++)
		fill(visited[i],visited[i]+n,false);
		
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]) continue;
			cnt2++;
			Q.push({i,j});
			visited[i][j]=true;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();
				int cx=cur.first,cy=cur.second;
				char cv=board2[cx][cy];
				
				for(int dir=0;dir<4;dir++){
					int nx=cx+dx[dir],ny=cy+dy[dir];
					if(nx<0||nx>=n||ny<0||ny>=n) continue;
					if(visited[nx][ny]) continue;
					if(cv!=board2[nx][ny]) continue;
					
					Q.push({nx,ny});
					visited[nx][ny]=true;	
				}
			}
		}
	}
	
	cout<<cnt<<" "<<cnt2;
	 
}
