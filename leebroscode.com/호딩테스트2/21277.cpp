#include<bits/stdc++.h>
using namespace std;

int n1,n2,m1,m2;
int board[50][50],board2[50][50];

//2��° �迭�� ���������� 90�� ȸ��. 
void rotate_array(int num){
	int new_board[50][50];
	while(num--){
		for(int i=0;i<m2;i++){
			for(int j=0;j<n2;j++){
				new_board[i][j]=board2[n2-1-j][i];
			}
		}	
	}
}
int main(){
	cin>>n1>>m1;
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			cin>>board[i][j];
		}
	}
	cin>>n2>>m2;
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			cin>>board[i][j];
		}
	}
}
