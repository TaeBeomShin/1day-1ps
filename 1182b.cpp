#include<bits/stdc++.h>
using namespace std;

int n,s,sum,cnt;
int arr[20];

void dfs(int i,int sum){
	//dfs ����. 
	/* 1.üũ�� 	
	 * 2.�������ΰ�? 	
	 * 3.�� �� �ִ°��� 	
	 * 4.�� �� �ִ°�? 	
	 * 5.���� 		
	 * 6.üũ�ƿ�
	 */
	if(i==n) return;//��������. 
	if(sum+arr[i]==s) cnt++;//cnt�� ������ų ����. 
	
	dfs(i+1,sum);//1. �������� �������. 
	dfs(i+1,sum+arr[i]);//2. ������ ���. 
}

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	cnt=0;
	dfs(0,0);
	
	cout<<cnt;
	
	return 0;	
}
