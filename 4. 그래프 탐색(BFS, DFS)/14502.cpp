#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

#define X first
#define Y second

typedef pair<int,int> pii;
int n,m,board[8][8], board2[8][8];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pii> v;

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		cin>>board[i][j];
		if(board[i][j]==0) v.push_back({i,j});
	}
	
	int ans=0;
	
	//벽 세울위치 3곳을 결정하기. 벡터에 {x,y} 꼴로 저장해놓고 인덱싱으로 하나씩 뽑음. = 천재.. 
	for(int a=0;a<v.size()-2;a++)for(int b=a+1;b<v.size()-1;b++)for(int c=b+1;c<v.size();c++){
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) board2[i][j]=board[i][j];
		
		
		board2[v[a].X][v[a].Y]=board2[v[b].X][v[b].Y]=board2[v[c].X][v[c].Y]=1;
		bool visited[8][8]={false,};
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			if(board2[i][j]!=2||visited[i][j]) continue;
			queue<pii> Q;
			Q.push({i,j});
			visited[i][j]=true;
			
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();
				int x=cur.X;int y=cur.Y;
				for(int k=0;k<4;k++){
					int nx=x+dx[k];
					int ny=y+dy[k];
					if(nx<0||nx>=n||ny<0||ny>=m) continue;
					if(board2[nx][ny]==1||visited[nx][ny]) continue;
					Q.push({nx,ny});
					board2[nx][ny]=2;
					visited[nx][ny]=2;
				}
			}
		}
		int temp=0;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(board2[i][j]==0) temp++;
		ans=max(ans,temp);
	}
	cout<<ans<<"\n";
}
