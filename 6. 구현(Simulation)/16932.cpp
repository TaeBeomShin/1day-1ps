#include<bits/stdc++.h>
using namespace std;
// BFS로 접근
 
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0}; 
int main(){
	int n,m;cin>>n>>m;
	int arr[n][m];
	
	vector<pair<int,int>> board;
	vector<pair<int,int>> start; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0) board.push_back({i,j});
			if(arr[i][j]==1) start.push_back({i,j});
		}
	}
	
	/*
	  1. 칸의 수 하나를 바꾼다.
	  2. 시작점을 바꾸어가며 바꾼판에서 모양의 최대 크기를 찾는다. 
	*/
	
	int maxn=0;
	
	for(int i=0;i<board.size();i++){
		//칸의 수 하나를 바꾼다. 
		int cx=board[i].first,cy=board[i].second;
		arr[cx][cy]=1;
		
		bool visited[n][m]={0,};
		queue <pair<int,int> > Q;
		int size=0;
		
		for(int j=0;j<start.size();j++){
			int sx=start[j].first,sy=start[j].second;
			if(visited[sx][sy]) continue; //방문한 점이면 지나간다.
			Q.push({sx,sy});
			visited[sx][sy]=true;
			size=1;
			
//			cout<<"check";
			while(!Q.empty()){
				auto cur=Q.front();Q.pop();
				int curx=cur.first,cury=cur.second;
				size++;
//				cout<<"check";
				
				for(int dir=0;dir<4;dir++){
					int nx=curx+dx[dir],ny=cury+dy[dir];
//					cout<<"check";
					if(nx<0||ny<0||nx>n||ny>m) continue; //밖으로 나가면.
					if(visited[nx][ny]) continue;
					if(arr[nx][ny]==0) continue;
					Q.push({nx,ny});
					visited[ny][ny]=true;
				}
			}
			maxn=max(size,maxn);
			cout<<size<<"\n";
		}
		arr[cx][cy]=0;
	}
	cout<<maxn;
} 
