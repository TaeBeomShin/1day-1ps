#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int dist[401][401];
int main(){
	fastio;
	int n,k;cin>>n>>k;
	for(int i=0;i<k;i++){
		int front,end;cin>>front>>end;
		dist[front-1][end-1]=1;
	}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(dist[i][j]==0) dist[i][j]=1e9;

	for(int i=0;i<n;i++) dist[i][i]=1e9;
		
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			
	int s;cin>>s;
	for(int i=0;i<s;i++){
		int start,end;cin>>start>>end;
		start-=1;end-=1;
		if(dist[start][end]>=1e9&&dist[end][start]>=1e9)
			cout<<"0\n";
		else if(dist[start][end]<1e9)
			cout<<"-1\n";
		else
			cout<<"1\n";
	}
}
