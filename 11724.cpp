#include <bits/stdc++.h>

using namespace std;

vector<int> a[1001]; //a:adjacent list;
bool check[1001];

void dfs(int node){
	check[node]=true;
	for(int i=0;i<a[node].size();i++){
		int next=a[node][i];
		if(check[next]==false) dfs(next);
	}
}
int main(){
	int t,m,n,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=0;i<k;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int components =0;
		for(int i=1;i<=n;i++){
			if(check[i]==false){
				dfs(i);
				components++;
			}
		}
		cout<<components;
	}
	return 0;
}
 
