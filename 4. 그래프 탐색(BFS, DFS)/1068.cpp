#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1068- 트리 
	
	so1) 구현 -> 실패.. 예외 케이스를 못걸러냄. 
	
	1. 리프노드 인지 파악, 해당노드를 부모노드를 가지는 노드가 없으면 리프노드
	2. 리프노드를 모두 저장하고 리프노드 중 부모가 지워지는 노드인 것 개수 빼기
	3. 출력. 
	
	sol2) dfs 이용. 
*/
int n,cut;
vector<int> adj[50];

int dfs(int curr){
	int ret=1;
	int child=0;
	for(auto ch:adj[curr]){
		if(ch==cut) continue;
		child+=dfs(ch);
	}
	if(child) return child;
	else return ret;
}
int main(){
	cin>>n;
	int root;
	for(int i=0;i<n;i++){
		int parent;cin>>parent;
		if(parent==-1) root=i;
		else adj[parent].push_back(i);
	}
	cin>>cut;
	if(root!=cut){
		cout<<dfs(root);
	}else{
		cout<<0;
	}
}
