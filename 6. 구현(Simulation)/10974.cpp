#include<bits/stdc++.h>
using namespace std;
/*
	��������, ��������, ��� ����.
	
	���� �⺻ ����. next_permutation �Լ� ���� ������ ����..  
*/
int main(){
	int n;cin>>n;
	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(i);
	
	do{
		for(int num : v) cout<<num<<" ";
		puts("");
	}while(next_permutation(v.begin(),v.end()));
} 
