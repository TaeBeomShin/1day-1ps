#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,s;cin>>n>>s;
	int psum[n+1]={0,},sum=0,length=0;
	
	for(int i=0;i<n;i++){
		int a; cin>>a;
		sum+=a;
		psum[i+1]=sum;
	}
	
	bool flag=false;
	/*
		-- �ð����⵵ O(n^2) --
		1. ���̸� 1�� �÷�������.
		2. psum�� �̿��� ���� ���Ѵ�.
		3. ���� s�� ������ ���̸� ��ȯ�Ѵ�. 
		
		�׻� Ʋ�ȴٰ� ���� ���� �� �� ������ ������ �ۼ��޴��� Ȯ���� ��. 
	*/
	
	for(int size=1;size<=n;size++){
		for(int i=0;i<=n-size;i++){
			int num=psum[i+size]-psum[i];
			if(num>=s){
				flag=true;
				length=size;
				break;
			}
		}
		if(flag) break;
	}
	cout<<length;
}
