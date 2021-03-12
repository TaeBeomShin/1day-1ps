#include<bits/stdc++.h>
using namespace std;

int n,num[100];
long long cnt;

//sol1) 브루트포스 실패. 
void dfs(int idx,int result){
	if(idx==n-2){
		if(result==num[n-1]){
			cnt++;
		}
		return;
	}
	if(result+num[idx+1]<=20){
		dfs(idx+1,result+num[idx+1]);
	}
	if(result-num[idx+1]>=0){
		dfs(idx+1,result-num[idx+1]);
	}
	return;
}
int main(){
	cin>>n;

	for(int i=0;i<n;i++) cin>>num[i];

	dfs(0,num[0]);
	cout<<cnt;
}
