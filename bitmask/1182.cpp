#include<iostream>
using namespace std;

int num[21]={0,};
int main(){
	int n,S;
	cin>>n>>S;
	for(int i=0;i<n;i++) cin>>num[i];
	
	int count=0;
	for(int i=1;i<(1<<n);i++){
	//�κ������� ����. 2^n-1��, ��� �κ����տ� ����, �������� ����. 
		int sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) sum+=num[j];
		}
		if(sum==S) count++;
	}
	cout<<count;
}
