#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 1068- Ʈ�� 
	
	so1) ���� -> ����.. ���� ���̽��� ���ɷ���. 
	
	1. ������� ���� �ľ�, �ش��带 �θ��带 ������ ��尡 ������ �������
	2. ������带 ��� �����ϰ� ������� �� �θ� �������� ����� �� ���� ����
	3. ���. 
	
	sol2) dfs �̿�. 
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
