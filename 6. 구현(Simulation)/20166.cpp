#include<bits/stdc++.h>
using namespace std;

int n,m,k;
char board[15][15];
vector<string> queries;
map<string,int> answers;

int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
void dfs(int x,int y,string s,int len){
	answers[s]++;
	if(len==5) return;
	
	for(int dir=0;dir<8;dir++){
		int nx=(x+dx[dir])%n,ny=(y+dy[dir])%m;
		if(nx<0) nx+=n;
		if(ny<0) ny+=m;
		
		dfs(nx,ny,s+board[nx][ny],len+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++) cin>>board[i];
	
	queries.resize(k);
	for(int i=0;i<k;i++) cin>>queries[i];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dfs(i,j,string(1,board[i][j]),1);
		}
	}
	
	for(string god:queries) cout<<answers[god]<<"\n";
	
}
