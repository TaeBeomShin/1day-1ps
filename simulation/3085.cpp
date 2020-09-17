#include<bits/stdc++.h>
using namespace std;

int N;
string board[51];

int maxcandy(){
	int result=1;
	for(int i=0;i<N;i++){
		int temp=-1;
		for(int j=1;j<N;j++){
			if(board[i][j-1]==board[i][j]) temp++;
			else{
				result=max(result,temp);
				temp=1;
			}
			result=max(result,temp);
		}
	}
	
	for(int i=0;i<N;i++){
		int temp=-1;
		for(int j=0;j<N-1;j++){
			if(board[j+1][i]==board[j][i]) temp++;
			else{
				result=max(result,temp);
				temp=1;
			}
			result=max(result,temp);
		}
	
	}
	return result;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++) cin>>board[i];
	
	int result=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++)
		{
			//¾ç ¿· swap
             swap(board[i][j], board[i][j + 1]);
             result = max(result, maxcandy());
             swap(board[i][j], board[i][j + 1]);

             //À§ ¾Æ·¡ swap
             swap(board[j][i], board[j + 1][i]);
             result = max(result, maxcandy());
             swap(board[j][i], board[j + 1][i]);
		}
	}
	cout<<result;
}
