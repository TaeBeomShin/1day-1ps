#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
	int n;cin>>n;
	int board[n][n];
	
	vector<pair<int,int>> position;
	vector<int> v(n*n);
	for(int i=0;i<n*n;i++) v[i]=1;
	v[0]=0,v[1]=0,v[2]=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			position.push_back({i,j});
		}
	}
	
	int ans=1e10;
	do{//꽃의 위치를 정함. 
		vector<pair<int,int>> flowers;
		for(int i=0;i<v.size();i++){
			if(v[i]==0) flowers.push_back({position[i].first,position[i].second});
			//씨앗을 심을 곳의 위치 저장. 
		}
		bool visited[n][n]={0,};
		bool check=true;
		int sum=0;
		for(int i=0;i<3;i++){
		//세 씨앗을 놓을 위치를 정했음.
			int curx=flowers[i].first,cury=flowers[i].second;
			if(visited[curx][cury]){//방문한 곳이라면 종료(꽃이 죽으니까) 
				check=false;
				break;
			}
			sum+=board[curx][cury];//방문한 곳이 아니면 현재위치의 값을 더함.
			visited[curx][cury]=true;
			
			for(int dir=0;dir<4;dir++){
				int nx=curx+dx[dir],ny=cury+dy[dir];
				if(nx<0||nx>=n||ny<0||ny>=n||visited[nx][ny]){//방문했거나 범위를 벗어나면 
					check=false;
					break;
				}
				sum+=board[nx][ny];//조건을 만족하면,  현재위치의 값을 더함.
				visited[nx][ny]=true;
			}
			if(!check) break;
		}
		if(!check) continue;
		ans=min(sum,ans);
	}while(next_permutation(v.begin(),v.end()));
	cout<<ans;
} 
