#include<bits/stdc++.h>
using namespace std;
int n,s,cnt,currentSum,val[20];

void dfs(int current){
	if(current==n) return;
	if(currentSum+val[current]==s) cnt++;
	dfs(current+1);
	currentSum+=val[current];
	dfs(current+1);
	currentSum-=val[current];
	//dfs�� ���������� �湮�ϱ��� ���·� �ǵ�����. 
}
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>val[i];
	dfs(0);
	cout<<cnt;
}
