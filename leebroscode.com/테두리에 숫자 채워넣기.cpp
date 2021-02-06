#include<bits/stdc++.h>
using namespace std;

bool in_range(int x,int y){
	return 0<=x&&x<4&&0<=y&&y<4;
}

int main(){
	int grid[4][4]={};
	
	int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
	int dir=0;
	int num=1;
	
	for(int x=0,y=0;;x=x+dx[dir],y=y+dy[dir]){
		grid[x][y]=num++;
		
		int new_x=x+dx[dir],new_y=y+dy[dir];
		if(!in_range(new_x,new_y)) dir=dir+1;
		if(new_x==0&&new_y==0) break;
	}
}
