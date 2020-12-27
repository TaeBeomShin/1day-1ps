#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define X first
#define Y second
using namespace std;

const int INF=int(1e9);
int t,n,dist[102][102];

int main(){
	fastio;
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,int> > v(n+2);
		for(int i=0;i<n+2;i++){
			int a,b;cin>>a>>b;
			v[i]={a,b};
		}
		
		for(int i=0;i<n+2;i++) fill(dist[i],dist[i]+n+2,INF);
		for(int i=0;i<n+2;i++)for(int j=0;j<n+2;j++){
			int distance=abs(v[j].X-v[i].X)+abs(v[j].Y-v[i].Y);
			if(distance<=1000) dist[i][j]=dist[j][i]=1;
		}
		
		for(int i=0;i<n+2;i++) dist[i][i]=0;
		
		for(int k=0;k<n+2;k++)for(int i=0;i<n+2;i++)for(int j=0;j<n+2;j++){
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		} 
		dist[0][n + 1] != INF ? cout << "happy\n" : cout << "sad\n";
		//마지막에 도달 가능한지 체크. 
	}
}
