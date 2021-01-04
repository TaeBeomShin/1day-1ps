#include<bits/stdc++.h>
using namespace std;
int dist[101][101];
int main(){
	int n,m;cin>>n>>m;
	/*
		플로이드 와샬로 경로가 있는지 확인한다.
		
		모든 정점에서 정점으로의 경로를 구한 다음에 가장 케빈베이컨의 수가 작은 정점을 출력한다. 
	*/
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dist[i][j]=1e8;
			
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		dist[a-1][b-1]=1;
		dist[b-1][a-1]=1;
	}
	
	// 정점간의 거리를 최댓값으로 초기화. 		
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	
	int minv=1e8,midx=0;

	for(int i=0;i<n;i++){
		int count=0;
		for(int j=0;j<n;j++)
			if(i!=j) count+=dist[i][j];
		
		if(count<minv){
			midx=i;
			minv=count;
		}
	}
	cout<<midx+1;
}
