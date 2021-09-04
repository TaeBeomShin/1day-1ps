#include<bits/stdc++.h>
using namespace std;
/**
* dfs ¹®Á¦. 
*/
int n,m;
int cnt;
vector<int> v[10001];
bool visited[10001];

void dfs(int current){
	visited[current]=true;
	
	for(int i=0;i<v[current].size();i++){
		if(visited[v[current][i]]){
			continue;
		}
		
		cnt++;
		dfs(v[current][i]);
	}
}
int main(){
	cin>>n>>m;
	
	int answer=0;
	vector<int> result;
	
	for(int i=0;i<m;i++){
		int computer1,computer2;cin>>computer1>>computer2;
		
		v[computer2].push_back(computer1);
	}
	
	for(int i=1;i<=n;i++){
		memset(visited,false,sizeof(visited));
		
		cnt=0;
		dfs(i);
		
		if(answer==cnt){
			result.push_back(i);
		}
		if(answer<cnt){
			answer=cnt;
			result.clear();
			result.push_back(i);
		}
	}
	
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
}
