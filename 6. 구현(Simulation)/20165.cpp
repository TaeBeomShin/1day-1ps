#include<bits/stdc++.h>
using namespace std;

int n,m,r,ans;
//도미노가 넘어졌는지 기록. 
int domino[101][101],board[101][101];

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

int direction(char d){
	if(d=='N') return 0;
	if(d=='E') return 1;
	if(d=='S') return 2;
	if(d=='W') return 3;
}

void attack(int x,int y,char dir){
	if(domino[x][y]==0) return;
	
	int d=direction(dir),cnt=domino[x][y];
	
	int nx=dx[d],ny=dy[d];
	while(x>=1&&x<=n&&y>=1&&y<=m&&cnt>=1){
		if(domino[x][y]) ans++;
		cnt=max(cnt-1,domino[x][y]-1);
		domino[x][y]=0;
		x+=nx,y+=ny;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>r;
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>domino[i][j],board[i][j]=domino[i][j];

	while(r--){
		int x,y,d;char dir;
		//행 Y열의 도미노를 D 방향으로 넘어트림. 
		cin>>x>>y>>dir;
		//이미 넘어진 도미노가 아닌경우. 
		attack(x,y,dir);
		
		int savex,savey;cin>>savex>>savey;
		domino[savex][savey]=board[savex][savey];
	}
			
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<(domino[i][j]==0?"F":"S")<<" ";
		}
		cout<<"\n";
	}
}
