#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int board[21][21];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int n;cin>>n;
	pair <int,int> size={2,0},pos;
	vector<pair<int,int>> fish;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]==9){
				pos={i,j};
			}else if(board[i][j]>=1){
				fish.push_back({i,j});
			}
		}
	}

	int ans=0;
	while(!fish.empty()){
		int mdist=1000;//최소거리.
		int midx;
		pair <int,int> next; //다음 목적지 
		
		for(int i=0;i<fish.size();i++){
			auto f=fish[i];
			int x=f.X,y=f.Y;
			if(size.X<=board[x][y]) continue;

			queue<pair<int,int>> Q;
			bool visited[n][n]={0,};//방문 여부 확인.
			visited[pos.X][pos.Y]=true;
			int dist[n][n]={0,};
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++){
					visited[i][j]=false;
					dist[i][j]=1000;
				}
			
			Q.push(pos);//현재 위치 넣는다.
			dist[pos.X][pos.Y]=0;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();		
				for(int dir=0;dir<4;dir++){
					int nx=cur.X+dx[dir],ny=cur.Y+dy[dir];
					if(nx<0||ny<0||nx>=n||ny>=n) continue; 
					if(size.X<board[nx][ny]) continue;
					if(visited[nx][ny]) continue;
					Q.push({nx,ny});
					dist[nx][ny]=min(dist[nx][ny],dist[cur.X][cur.Y]+1);
					visited[nx][ny]=true;
				}
			}
			if(dist[x][y]<mdist){		
				next={x,y};
				mdist=dist[x][y];
				midx=i;
			}else if(dist[x][y]==mdist){
				if(x<next.X){
					next={x,y};
					mdist=dist[x][y];
					midx=i;
				}else if(x==next.X){
					if(y<next.Y){
						next={x,y};
						mdist=dist[x][y];
						midx=i;
					}
				}
			}
		}
		if(mdist==1000)
			break;
		
		fish.erase(fish.begin()+midx);
		board[next.X][next.Y]=9;
		board[pos.X][pos.Y]=0;
		pos=next;
		ans+=mdist;

		size.Y++;
		if(size.Y==size.X){
			size.X++;
			size.Y=0;
		}

	}
	cout<<ans;
}
