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
			
			//정점 제거하고 인접한 노드의 indegree 감소시킴. 
			for(int i=0;i<v[vertex].size();i++){
				int next=v[vertex][i];
				indegree[next]--;
			}
			//indegree가 0인 정점을 찾는다.
			for(int i=1;i<=m;i++){
				if(indegree[i]==0&&!visited[i]){//indegree가 0인 노드의 strahler 값을 결정해야함.
					int maxn=1;
					//가장큰 strahler 값 구함. 
					for(int j=0;j<parents[i].size();j++){
						int parent_v=parents[i][j];
						maxn=max(maxn,strahler[parent_v]);
					}
					int cnt=0;
					//가장 큰 값이 2개이상 나왔는지 확인. 
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
