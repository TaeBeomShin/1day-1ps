#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[11];

void printCombination(){
	for(int i=1;i<=n;i++) if(visited[i]) cout<<i<<" ";
	puts("");
}
void dfs(int cnt,int lastNumber){
	if(cnt==m){
		printCombination();
		return;
	}
	
	for(int i=lastNumber+1;i<=n;i++){
		visited[i]=true;
		dfs(cnt+1,i);
		visited[i]=false;
	}
}
int main(){
	cin>>n>>m;
	dfs(0,0);
}
