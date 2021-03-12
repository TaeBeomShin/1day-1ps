#include<bits/stdc++.h>
using namespace std;

int ans=0,n;
vector<pair<int,int> > v;

vector<int> selected;

void calculate(){
	
	bool visited[1001]={0,};
	int size=selected.size();
	for(int i=0;i<selected.size();i++){
		int num=selected[i];
		int s=v[num].first,e=v[num].second;
		for(int j=s;j<=e;j++){
			if(visited[j]) size=0; 
			visited[j]=true;
		}
	}
	ans=max(ans,size);
}

void dfs(int idx){
	if(idx==n){
		calculate();
		return;
	}
	selected.push_back(idx);
	dfs(idx+1);
	selected.pop_back();
	dfs(idx+1);
}

int main(){
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
	dfs(0);
	
	cout<<ans;
}
