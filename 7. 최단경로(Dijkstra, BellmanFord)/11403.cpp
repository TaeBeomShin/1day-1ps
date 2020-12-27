#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

int dist[101][101];
int main(){
	int n;cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dist[i][j];
			if(dist[i][j]==0) dist[i][j]=INF;
		}
	}
	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			(dist[i][j]<1000)?cout<<"1 ":cout<<"0 ";
		}
		cout<<"\n";
	}
}
