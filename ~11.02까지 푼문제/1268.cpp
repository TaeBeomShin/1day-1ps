#include<bits/stdc++.h>
using namespace std;
int A[1001][5];

int main(){
	int n,mn=0,mi=0;cin>>n;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++) cin>>A[i][j];
	
	for(int i=0;i<n;i++){
		int c=0;
		bool v[n]={0,};
		for(int j=0;j<5;j++){
			for(int k=0;k<n;k++){
				if(!v[k]&&A[i][j]==A[k][j]){
					v[k]=true;
					c++;
				}
			}	
		}
		if(c>mn){
			mn=c;
			mi=i;
		}
	}
	cout<<mi+1;
}
