#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	bool row[50]={0,}, col[50]={0,};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char c;cin>>c;
			if(c=='X') row[i]=col[j]=true;
		}
	}
	cout<<max(n-accumulate(row,row+n,0),m-accumulate(col,col+m,0));
}
