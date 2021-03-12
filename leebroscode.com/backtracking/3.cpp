#include<bits/stdc++.h>
using namespace std;

pair<int,int> bomb[4][4]={
{{0,1},{0,2},{0,-1},{0,-2}},
{{0,1},{0,-1},{1,0},{-1,0}},
{{1,1},{-1,1},{-1,-1},{1,-1}}
};

int n,m,ans=0;
int board[20][20];

vector<pair<int,int> > v;
vector<int> bombT;

void calculate(){
	int sum=0;
	bool new_board[n][n]={0,};
	
	for(int i=0;i<v.size();i++){
		auto cur=v[i];
		int cx=v[i].first,cy=v[i].second;
		
		new_board[cx][cy]=true;
		
		for(int j=0;j<4;j++){
			auto next=bomb[bombT[i]][j];
			int nx=cx+next.first,ny=cy+next.second;
			if(nx<0||nx>=n||ny<0||ny>=n) continue;
			new_board[nx][ny]=true;
		}
	}
	
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(new_board[i][j]) cnt++; 
		
	ans=max(ans,cnt);
}
void dfs(int count){
	if(count==m){
		calculate();
		return;
	}
	for(int i=0;i<3;i++){
		bombT.push_back(i);		
		dfs(count+1);
		bombT.pop_back();
	}
}
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>board[i][j];
			if(board[i][j]==1) v.push_back({i,j}); 
		}
	}
	m=int(v.size());
	dfs(0);
	
	cout<<ans;
}
