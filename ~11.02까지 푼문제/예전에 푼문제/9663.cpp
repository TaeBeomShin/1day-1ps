#include<bits/stdc++.h>
using namespace std;

int board[14][14] ={0,};
int n,answer=0;

bool promising(int i,int count){
	int x,y;
	for(x=0;x<count;x++){
		if(board[i][x]) return false;
	}
	for(x=count-1,y=i-1;y>=0;x--,y--){
		if(board[y][x]) return false;
	}
	for(x=count-1,y=i+1;y<n;x--,y++){
		if(board[y][x]) return false;
	}
	return true;
}

void dfs(int count){
	if(count==n){
		answer++;
		return;
	}
	for(int i=0;i<n;i++){
		if(!board[i][count]&&promising(i,count)){
			board[i][count]=true;
			dfs(count+1);
			board[i][count]=false;
		}
	}
}	

int main(){
	cin>>n;
	dfs(0);
	cout<<answer;
	
}
