#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	vector<int> v[n];
	int visited[n];
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
	}
	queue<pair<int, int>> Q;
	Q.push({x,0});
	
	vector<int> ans;
	while(!Q.empty()){
		auto cur=Q.front();
		int pos=cur.first;
		int dist=cur.second;
		visited[pos]=1;
		Q.pop();
		
		for(int i=0;i<v[pos].size();i++){
			int next=v[pos][i];
			if(visited[next]) continue;
			if(dist+1==k){
				cout<<"check";
				ans.push_back(next);
				continue;
			}
			Q.push({next,dist+1});
		}
	}
	sort(ans.begin(),ans.end());
	unique(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<"\n";
	if(ans.empty())cout<<"-1";
}
