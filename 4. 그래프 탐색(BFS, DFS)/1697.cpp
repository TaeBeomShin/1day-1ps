#include<bits/stdc++.h>
using namespace std;

int dist[200001];
bool visited[200001]={false};
int dir[3]={1,-1,2};

int main(){
	int n,k;cin>>n>>k;
	
	//최댓값으로 거리를 채움. 
	fill(dist,dist+200001,1e7); 
	/*
		가능한 연산 : 앞 +1 또는 뒤 -1 로 이동, 순간이동 2*x
		bfs를 통해 최단경로 찾기. 
	*/
	
	queue<int> Q;
	dist[n]=0;
	Q.push(n);
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		
		for(int i=0;i<3;i++){
			int next;
			(i==2)?next=2*cur:next=cur+dir[i];
			if(next<0||next>200000) continue;
			if(dist[next]<dist[cur]+1) continue;
			
			Q.push(next);
			dist[next]=dist[cur]+1;
		}
	}
	cout<<dist[k];
}
