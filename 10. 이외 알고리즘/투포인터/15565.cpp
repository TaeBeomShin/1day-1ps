/*
	�������� �⺻.
	1. start,end �����͸� 0���� �д�.
	2. start ~ end ���� ������ ������ k���� ������ end�� �ø���, ũ�ų� ������ start�� �ø���.
	3. �ּڰ��� ������ �ּڰ� ���, �ƴϸ� -1 �� ����Ѵ�.  
*/
#include<bits/stdc++.h>
using namespace std;

int lion[1000000]={0,}; 
int main(){
	int n,k;cin>>n>>k;
	
	for(int i=0;i<n;i++) cin>>lion[i];
	
	int start=0,end=0;
	
	int count;
	(lion[0]==1)?count=1:count=0;
	int size=1e7;
	while(start<=end&&end<n){
//		cout<<start<<" "<<end<<" "<<count<<"\n";
		if(count<k){
			end++;
			if(lion[end]==1) count++;
		}else{
			size=min(size,end-start+1);
			if(lion[start]==1) count--;
			start++;
		}
	}
	(size==1e7)?cout<<-1:cout<<size;
}
