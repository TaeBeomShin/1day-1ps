#include<bits/stdc++.h>
using namespace std;

//블럭은 총 6종류.

int blocks[6][3][2]={
	{{0,0},{1,0},{1,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{0,1}},
	{{1,0},{0,1},{1,1}},
	{{0,0},{1,0},{2,0}},
	{{0,0},{0,1},{0,2}}
};

int board[201][201]={0,};
int main(){
	int n,m;cin>>n>>m;
	
	//1. 값을 받는다. 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>board[i][j];
		}
	}
	
	//2. 블록을 하나씩 놓으면서 최대값을 찾는다.
	
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int cx=i,cy=j;
			for(int k=0;k<6;k++){//블록을 선택한다. 
				int sum=0;
				for(int dir=0;dir<3;dir++){
					int nx=cx+blocks[k][dir][0];
					int ny=cy+blocks[k][dir][1];
					if(nx<0||nx>n||ny<0||ny>m) continue;
					sum+=board[nx][ny];
				}
				ans=max(sum,ans);
			}
			
		}
	} 
	cout<<ans;

}
