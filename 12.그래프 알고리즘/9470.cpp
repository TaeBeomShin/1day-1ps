#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int k,m,p;cin>>k>>m>>p;
		int indegree[m+1]={0,},strahler[m+1]={0,};
		bool visited[m+1]={0,};
		vector<int> v[m+1];
		vector<int> parents[m+1];
		
		for(int i=0;i<p;i++){
			int a,b;cin>>a>>b;
			indegree[b]++;
			v[a].push_back(b);
			parents[b].push_back(a);
		}
		
		queue<pair<int,int> > Q;
		for(int i=1;i<=m;i++){
			if(indegree[i]==0){
				Q.push({i,1});
				strahler[i]=1;
			}
		}
		
		while(!Q.empty()){
			auto cur=Q.front();Q.pop();
			int vertex=cur.first,value=cur.second;
			
			//���� �����ϰ� ������ ����� indegree ���ҽ�Ŵ. 
			for(int i=0;i<v[vertex].size();i++){
				int next=v[vertex][i];
				indegree[next]--;
			}
			//indegree�� 0�� ������ ã�´�.
			for(int i=1;i<=m;i++){
				if(indegree[i]==0&&!visited[i]){//indegree�� 0�� ����� strahler ���� �����ؾ���.
					int maxn=1;
					//����ū strahler �� ����. 
					for(int j=0;j<parents[i].size();j++){
						int parent_v=parents[i][j];
						maxn=max(maxn,strahler[parent_v]);
					}
					int cnt=0;
					//���� ū ���� 2���̻� ���Դ��� Ȯ��. 
					for(int j=0;j<parents[i].size();j++){
						int parent_v=parents[i][j];
						if(maxn==strahler[parent_v]) cnt++;
					}
					
					if(cnt>=2){
						Q.push({i,maxn+1});
						strahler[i]=maxn+1;
					}else{
						Q.push({i,maxn});
						strahler[i]=maxn;
					}
					visited[i]=true;
				}
			} 
		}
		int ans=0;
		for(int i=1;i<=m;i++)
			ans=max(ans,strahler[i]);
		
		cout<<k<<" "<<ans<<"\n";
	}
}
