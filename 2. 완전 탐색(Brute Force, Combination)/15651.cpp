#include<bits/stdc++.h>
using namespace std;

int n,m;
bool selected[9];
void dfs(int count){
	//���� ���� : m���� ��� �����. 
	if(count==m){
		for(int i=1;i<=8;i++)
			cout<<selected[i]<<" ";
		puts("");
		return;
	}else{//m���� ���� �������, ���ǿ� �°� ���� �����. 
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
	 �ڿ��� n�� m�� �־����� ��
	 1. 1 ~ n������ �ڿ��� �߿��� m���� �� ����.
	 2. �ߺ����. 
	*/
	dfs(0);
}
