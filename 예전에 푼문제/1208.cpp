#include<bits/stdc++.h>
using namespace std;

int n,s,sum,cnt;
int num[40];

void dfs(int i,int sum){//dfs(i,sum) i��° ���Ҹ� �湮���� ��, sum ��. 
	if(i==n) return;//���� ����. 
	if(sum+num[i]==s) cnt++;
	
	dfs(i+1,sum);
	dfs(i+1,sum+num[i]);
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>num[i];
	
	cnt=0;
	dfs(0,0);
	
	cout<<cnt;
	
	return 0;
}
