#include<bits/stdc++.h>
using namespace std;

int main(){//위상정렬, DAG 형태의 그래프에서 위상정렬 가능. 
	int n,m,indegree[1000]={0};
	vector<int> adj[1000];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int k,prev,curr;
		cin>>k;
		if(k==0) continue;
		
		cin>>prev;
		for(int i=1;i<k;i++){
			cin>>curr;
			indegree[curr-1]++;
			adj[prev-1].push_back(curr-1);
			prev=curr;
		}
	}
	int result[1000];
	queue<int> Q;
	for(int i=0;i<n;i++)//indegree가 0인 정점을 큐에 모두 넣는다. 
		if(indegree[i]==0) Q.push(i);
	
	for(int i=0;i<n;i++){//정점의 개수만큼 행동을 반독. 
		if(Q.empty()){
			puts.("0");
			return 0;
		}
		int curr=Q.front();
		Q.pop();//큐의 front 원소를 빼서 그 정점에서 나가는 간선을 모두산제. 
		result[i]=curr+1;//큐에서 빼는 정점 순서가 위상정렬 결과. 
		for(int nex:adj[curr])
			if(--indegree[next]==0) Q.push(next);//indegree가 0인 간선 생기면 Q에 넣음. 
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<"\n";
} 
