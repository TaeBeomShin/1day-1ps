#include<bits/stdc++.h>
using namespace std;

/**
* 단순구현 문제. 
*/

int n;
int	dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
char answerBoard[10][10], playBoard[10][10], printBoard[10][10];

int countNearMine(int i,int j);
bool checkMineOpened(int i,int j);

int main(){
	cin>>n;
	
	bool mineOpened=false;
	
	for(int i=0;i<n;i++){
		cin>>answerBoard[i];
	}
	for(int i=0;i<n;i++){
		cin>>playBoard[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			int mineCount= countNearMine(i,j);
			mineOpened= checkMineOpened(i,j);
			
			if(playBoard[i][j]=='x'){
				printBoard[i][j]='0'+mineCount;	
			}else{
				printBoard[i][j]='.';
			}
		}
	}
	
	if(mineOpened){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(answerBoard[i][j]=='*'){
					printBoard[i][j]='*';
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<printBoard[i]<<"\n";
	}
}

int countNearMine(int i, int j){
	int mineCount=0;
	for(int dir=0;dir<8;dir++){
		int nx=i+dx[dir],ny=j+dy[dir];
		
		if(nx<0||ny<0||nx>=n||ny>=n){
			continue;
		}
		
		if(answerBoard[nx][ny]=='*'){
			mineCount++;
		}
	}
	
	return mineCount;
}

bool checkMineOpened(int i,int j){
	return answerBoard[i][j]=='*'&&playBoard[i][j]=='x';
}
