#include<iostream>

using namespace std;

char board[51][51]={0,};
int min(int a,int b){
	if(a>=b) return b;
	else return a;
}

int whiteFirst(int y,int x){
	int count=0;
	for(int i=y;i<=y+7;i++){
		for(int j=x;j<=x+7;j++){
			if(i%2==y%2&j%2==x%2&board[i][j]=='B') count++;
			if(i%2==y%2&j%2==(x+1)%2&board[i][j]=='W') count++;
			if(i%2==(y+1)%2&j%2==x%2&board[i][j]=='W') count++;
			if(i%2==(y+1)%2&j%2==(x+1)%2&board[i][j]=='B') count++;
		}
	}
	return count;
}

int blackFirst(int y,int x){
	int count=0;
	for(int i=y;i<=y+7;i++){
		for(int j=x;j<=x+7;j++){
			if(i%2==y%2&j%2==x%2&board[i][j]=='W') count++;
			if(i%2==y%2&j%2==(x+1)%2&board[i][j]=='B') count++;
			if(i%2==(y+1)%2&j%2==x%2&board[i][j]=='B') count++;
			if(i%2==(y+1)%2&j%2==(x+1)%2&board[i][j]=='W') count++;
		}
	}
	return count;
}
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>board[i][j];
		}
	}
	//왜 scanf로 받으면 공백도 같이받아지는 걸까. 
	
	int blackfirst,whitefirst=0;
	
	int result =64;
	for(int i=1;i<=N-7;i++){
		for(int j=1;j<=M-7;j++){
			result=min(result,min(blackFirst(i,j),whiteFirst(i,j)));
		}
	}
	
	cout<<result;
	return 0;
}
