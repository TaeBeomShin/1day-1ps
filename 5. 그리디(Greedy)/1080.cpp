#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	int A[n][m]={0,},B[n][m]={0,};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&A[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&B[i][j]);
		}
	}
}
