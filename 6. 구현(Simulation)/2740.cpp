#include<bits/stdc++.h>
using namespace std;

int A[101][101];
int B[101][101]; 
int main(){
	int n,m;cin>>n>>m;
	//n*m 크기의 행렬과 m*n크기의 행렬이 주어졌을때 두행렬을 곱하는 프로그램
	//n,m이 100보다 작으므로 for문만을 이용해서 가능함.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			cin>>>B[i][j];
		}
	}
}
