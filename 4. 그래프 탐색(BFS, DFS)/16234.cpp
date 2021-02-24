#include<bits/stdc++.h>
using namespace std;

const int MAX=50;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

int n,l,r;
int sum,num;
int board[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int,int>> v;

void DFS(int y,int x){
	for(int dir=0;dir<4;dir++){
		int nx=x+dx[dir], ny=y+dy[dir];
		int diff=abs(board[y][x]-board[ny][nx]);
		if(nx<0||nx>=n||ny<0||ny>=n) continue;
		if(l<=diff&&diff<=r&&!visited[ny][nx]){
			visited[ny][nx]=true;
			v.push_back({ny,nx});
			sum+=board[ny][nx];
			num++;
			DFS(ny,nx);
		}
	}
}
int main(){
	cin>>n>>l>>r;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>board[i][j];
	
	int result=0;
	while(true){
		memset(visited,false,sizeof(visited));
		bool found=false;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i][j]) continue;
				
				visited[i][j]=true;
				num=1;
				sum=board[i][j];
				
				v.clear();
				v.push_back({i,j});
				DFS(i,j);
				
				if(num>=2){
					found=true;
					for(int i=0;i<v.size();i++)
						board[v[i].first][v[i].second]=sum/num;
				}
			}
		}
		if(found)
			result++;
		else
			break;
	}
	
	cout<<result<<"\n";
}
