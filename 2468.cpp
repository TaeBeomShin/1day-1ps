#include<bits/stdc++.h>
using namespace std;


int maps[101][101];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
	int n;cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>maps[i][j];
		
	int mn=0;

	for(int rain=0;rain<=100;rain++){
		int count=0;
		int visit[101][101]={false,};

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				
				if(maps[i][j]<=rain||visit[i][j]) continue;
				count++;
				
				queue <pair <int,int> > Q;
				visit[i][j]=true;
				Q.push({i,j});
//				cout<<rain<<" "<<i<<" "<<j<<"\n";
				
				while(!Q.empty()){
					auto current=Q.front();Q.pop();
					
					for(int dir=0;dir<4;dir++){
						int nx=current.first+dx[dir];
						int ny=current.second+dy[dir];
						
						if(visit[nx][ny]==true) continue;// 이미 방문했음. 
						if(nx<0||nx>=n||ny<0||ny>=n) continue; // 행렬 밖을 나감. 
						if(maps[nx][ny]<=rain) continue;
						
						Q.push({nx,ny});
						visit[nx][ny]=true;
		
					}
				}
			}
		}
		mn=max(count,mn);
	}
	
	cout<<mn;
}
