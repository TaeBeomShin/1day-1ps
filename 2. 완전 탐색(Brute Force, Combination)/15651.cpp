#include<bits/stdc++.h>
using namespace std;

int n,m;
bool selected[9];
void dfs(int count){
	//종료 조건 : m개를 모두 골랐음. 
	if(count==m){
		for(int i=1;i<=8;i++)
			cout<<selected[i]<<" ";
		puts("");
		return;
	}else{//m개를 아직 못골랐음, 조건에 맞게 고르게 만든다. 
		for(int i=1;i<=n;i++){
			selected[i]=i;
			dfs(count+1);
			selected[i]=0;
		}
	}
	
}
int main(){
	cin>>n>>m;
	/*
	 자연수 n과 m이 주어졌을 때
	 1. 1 ~ n까지의 자연수 중에서 m개를 고른 수열.
	 2. 중복허용. 
	*/
	dfs(0);
}
