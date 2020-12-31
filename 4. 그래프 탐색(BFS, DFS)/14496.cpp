#include<bits/stdc++.h>
using namespace std;

/*bfs�� �ƴ�ô�ϴ� �������� bfs����

������ �� �о�� a -> b�� ���� �ִܰ�θ� ���ϴ� �������� �ľǰ����ϴ�.

�������� bfs�� ������ Ǯ���̴�.

1. input�� �Է¹޴´�, ��������Ʈ�� �����鰣�� ���Ῡ�θ� �����Ѵ�.

2. Q�� ����ְ� bfs�� �����Ѵ�. dist�迭�� ���� �湮���� �ʾ����� �����Ѵ�.

3. ����� ����Ѵ� (dist�� -1�� �ʱ�ȭ�ؼ� �湮�Ҽ� ������ -1�� ��µǵ��� ����.) 
	 
*/
int main(){
	int a,b,n,m;cin>>a>>b>>n>>m;
	vector<int> v[n+1];
	int dist[n+1];
	fill(dist,dist+n+1,-1);
	
	for(int i=0;i<m;i++){
		int c,d;cin>>c>>d;
		v[c].push_back(d);
		v[d].push_back(c);
	}
	
	queue<int> Q;
	Q.push(a);dist[a]=0;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		for(int i=0;i<v[cur].size();i++){
			int next=v[cur][i];
			if(dist[next]!=-1) continue;
			Q.push(next);
			dist[next]=dist[cur]+1;
		}
	}
	cout<<dist[b];
}
