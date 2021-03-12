#include<bits/stdc++.h>
using namespace std;

int k,n;
vector<int> v;

void Print(){
	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
	puts("");
}

void dfs(int idx){
	if(idx==n){
		if(v.size()==n) Print();
		return;
	}
	for(int i=0;i<k;i++){
		v.push_back(i+1);
		dfs(idx+1);
		v.pop_back();
	}
	
}
int main(){
	cin>>k>>n;
	
	dfs(0);
}
