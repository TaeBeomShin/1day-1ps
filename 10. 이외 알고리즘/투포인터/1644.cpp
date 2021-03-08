#include<bits/stdc++.h>
#define MAX 5000000
using namespace std;
/*
	BOJ 1644 - �����佺�׳׽� + ��������
	
	1. �Ҽ������ ���Ѵ�.
	2. �������͸� �̿��ؼ� �������� n�� ��� cnt++���ش�. 
*/
bool sosu[MAX]={0,};
int main(){
	int n;cin>>n;
	vector<int> v;
	
	for(int i=2;i<=int(sqrt(MAX));i++){
		if(sosu[i]) continue;
		for(int j=i*2;j<=MAX;j+=i){
			sosu[j]=true;
		}
	}
	for(int i=2;i<=MAX;i++) if(!sosu[i]) v.push_back(i);
	
	int size=v.size();
	
	int s=0,e=0;
	int cnt=0;
	
	while(s<=e){
		int result=0;
		for(int i=s;i<=e;i++) result+=v[i];	
		
		if(result<n){
			e++;
		}else if(result>=n){
			s++;
			if(result==n) cnt++;
		}
		
		if(v[s]>n) break;
	}
	
	cout<<cnt;
} 
