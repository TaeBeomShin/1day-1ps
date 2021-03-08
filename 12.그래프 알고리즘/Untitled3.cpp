#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n,m,k;
vector<int> adj[MAX];
int cnt[MAX]={0,},indegree[MAX]={0,};
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;

	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	int command,a;
	bool ans=true;
	for(int i=0;i<k;i++){
		cin>>command>>a;
		if(command==1){
		//이 건물을 건설하기 위해 요구되는 건물이 지어져있는가? 
			if(indegree[a]==0){
				cnt[a]++;
				if(cnt[a]==1){//처음 건물을 지음.
					//A 가 지어졌으므로, A아래의 건물들의 INDEGREE 줄임. 
					for(int j=0;j<adj[a].size();j++){
						int next=adj[a][j]; 
						indegree[next]--;
					}
				}
			}else{
				ans=false;
			}
		}else{
			//건설한 적 있는 건물인 경우. 
			if(cnt[a]>0){
				cnt[a]--;
				if(cnt[a]==0){
					for(int j=0;j<adj[a].size();j++){
						int next=adj[a][j];
						indegree[next]++;
					}
				}
			}else{
				ans=false;
			}
		}
	}
	(ans)?cout<<"King-God-Emperor":cout<<"Lier!";
}
