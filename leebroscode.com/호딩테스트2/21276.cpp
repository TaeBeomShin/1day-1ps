#include<bits/stdc++.h>
using namespace std;

int n,m;
map<string,int>map_names;
string names[1005];
vector<int> con[1005];
vector<string> child[1005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>names[i];
		map_names[names[i]]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		string x,y;cin>>x>>y;
		con[map_names[x]].push_back(map_names[y]);
	}
	
	vector<string> roots;
	for(int i=1;i<=n;i++){
		for(int j:con[i]){
			//트리의 부모이면 바로 아래보다 1개가 더 많음. 
			if(con[j].size()==con[i].size()-1){
				child[j].push_back(names[i]);
			}
		}
		if(con[i].size()==0) roots.push_back(names[i]);
	}
	cout<<roots.size()<<"\n";
	sort(roots.begin(),roots.end());
	for (string& root : roots) cout << root << " ";
	puts("");
	
	for(auto it:map_names){
		int idx=it.second;
		cout<<it.first<<" "<<child[idx].size();
		sort(child[idx].begin(),child[idx].end());
		for(string& ch:child[idx]) cout<<" "<<ch;
		cout<<"\n";
	}
}
