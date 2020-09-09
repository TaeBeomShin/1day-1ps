//���� ����Ʈ �̿�.
//���� ����Ʈ A[i] ���� i�� ����� ������ ����Ʈ�� ���Ҹ� ������.
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

vector<int> a[1001];//��������Ʈ �迭. 
bool check[1001];//�湮üũ�ϴ� �迭. 

//dfs�� ��������Ʈ�� �̿��Ͽ� ��������� ����. 
void dfs(int node){
	check[node]=true;
	cout<<node<<" ";
	for(int i=0;i<a[node].size();i++){
		int next=a[node][i];//node�� ����� i��° ����. 
		if(check[next]==false) dfs(next);//�湮���� ���� ������ ���� dfs ������.
		//��������Ʈ�� �����߱⶧����, ��������� ���������� ǥ�����ص���. 
	}
}

//bfs�� ť�ڷ����� �̿��Ͽ��� ������. bfs�� �ܰ躰�� ����ȴ�. 
void bfs(int start){
	queue<int> q;
	memset(check,false,sizeof(check));
	check[start]=true;
	q.push(start);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i=0;i<a[node].size();i++){
			int next=a[node][i];
			if(check[next]==false){
				check[next]=true;
				q.push(next);
			}
		}
	}
}

int main(){
	int n,m,start;
	cin>>n>>m>>start;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);// ��������Ʈ a�� u��° ����Ʈ�� v�� ����. 
		a[v].push_back(u);// ��������Ʈ a�� v��° ����Ʈ�� u�� ����. 
	}
	for(int i=1;i<=n;i++) sort(a[i].begin(),a[i].end());//������ �����ϱ� ����, �������� �������� ������ �����Ѵ�. 
	
	dfs(start);
	puts(" ");
	bfs(start);

	return 0;
}
