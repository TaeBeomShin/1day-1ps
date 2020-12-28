#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

vector<pair <int,int> > v[10001];
bool visited[10002]={0,};
int n,mdist=0,midx;
/*
 �������ٹ�
 1. ��Ʈ��忡�� ���� �ָ��ִ� ��带 ���Ѵ�.(1��° dfs ����)
 2. ���� ��忡�� ���� �� �������� �Ÿ��� ���Ѵ�.(2��° dfs����) 
 3. ������ ����Ѵ�.
 
 �ٸ�Ǯ�� 
 sol2) ���ͽ�Ʈ�� �˰����� 2�� ����(���� dfs)�� ����
 sol3) DP�� �̿��� Ǯ�� -> ���������ʿ�
  
 ������ Ǯ�̸� ��� �����ؼ� github �� ��α׿� ����. 
*/
void dfs(int node,int dist){
	if(visited[node]) return;
	if(dist>mdist){
		midx=node;
		mdist=dist;
	}
	visited[node]=true;
	for(int i=0;i<v[node].size();i++)
		dfs(v[node][i].first,dist+v[node][i].second);
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,c;cin>>a>>b>>c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	dfs(1,0);
	fill(visited,visited+n+1,0);
	mdist=0;
	dfs(midx,0);
	cout<<mdist;
}

