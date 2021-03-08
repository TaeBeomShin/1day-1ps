#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;cin>>t;
	while(t--){
		int n,m,k;cin>>k>>n>>m;
		vector<int> adj[n];
		int indegree[n]={0,},order[n]={0,},mx[n]={0,};
		while(m--){
			int a,b;cin>>a>>b;
			adj[--a].push_back(--b);
			indegree[b]++;
		}
		
		queue<int> Q;
		for(int i=0;i<n;i++){
			if(indegree[i]==0){
				Q.push(i),order[i]=1;
			}
		}
		while(!Q.empty()){
			int cur=Q.front();Q.pop();
			
			for(int next:adj[cur]){
				if(order[next]==order[cur]&&mx[next]==order[cur]) order[next]++;
				else if(order[next]<order[cur]) order[next]=order[cur];
				mx[next]=max(mx[next],order[cur]);
				if(--indegree[next]==0) Q.push(next);
			}
		}
		cout<<k<<" "<<order[n-1]<<"\n";
	}
}
