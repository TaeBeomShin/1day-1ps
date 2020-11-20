#include<bits/stdc++.h>
using namespace std;

int main(){
	//필요한 공간 인접행렬, indegree 저정할 배열, 원소 저장할 배열. 
	int n;cin>>n;
	int time[500],result[500]={0};
	int indegree[500]={0};
	vector<int> adj[500];
	queue<int> Q;
	
	for(int i=0;i<n;i++){
		cin>>time[i];//원소를 입력받습니다.(i번호 건물이 지어지는데 걸리는시간) 
		while(true){
			int pre;
			cin>>pre;//i건물을 짓기위해 먼저 지어야하는 건물. 
			if(pre==-1) break;//-1를 받으면 종료. 
			indegree[i]++;//indegree를 올림. 
			adj[pre-1].push_back(i);//인접행렬에 i를 집어넣습니다. 
		}
		if(indegree[i]==0){//indegree가 0이면 
			result[i]=time[i];//결과로 time[i[를 넣음. 
			Q.push(i);//Q에 i를 집어넣음. 
		}
	}
	for(int i=0;i<n;i++){
		int cur=Q.front();
		Q.pop();
		for(int next:adj[cur]){
			result[next]=max(result[next],result[cur]+time[next]);
			if(--indegree[next]==0) Q.push(next);
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<result[i]<<"\n";
} 
