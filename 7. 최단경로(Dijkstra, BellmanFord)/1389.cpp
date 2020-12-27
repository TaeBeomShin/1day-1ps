#include<bits/stdc++.h>
using namespace std;
int d[101][101];
int main(){
	int n,m;cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=1e9;
			
	for(int i=0;i<m;i++){//무방향 그래프이므로. 
		int s,e;cin>>s>>e;
		d[s-1][e-1]=1;
		d[e-1][s-1]=1;
	}
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	
	int mn=1e9,midx=0;
	
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<n;j++)
			if(i!=j) sum+=d[i][j];

		if(mn>sum){
			mn=sum;
			midx=i;
		}
	}
	cout<<midx+1;
}
