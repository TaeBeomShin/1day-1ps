#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define X first
#define Y second //pair���� first,seoncd�� �ٿ��� �������� ���. 
using namespace std;

int board[501][501];//1�� �Ķ�ĭ, 0�� ����ĭ�� ����. 
bool visited[501][501];//�ش�ĭ�� �湮�ߴ��� ����. 
int n,m; 
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};//����¿� �׹���. 

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>board[i][j];
	
	int mx=0;//������ �ִ밪 
	int count=0;//�׸��� ��. 
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j] or board[i][j]==0) continue;//������ ����, �湮���� �ʾҰ�, 1�� ��ĥ�Ǿ��ִ�.
			count++;
			queue <pair<int,int> > Q;//ť�� �ְ��� �湮ǥ��. 
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
