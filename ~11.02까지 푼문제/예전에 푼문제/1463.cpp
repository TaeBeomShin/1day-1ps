#include<iostream>

using namespace std;

int main(){
//�� D[N]=min(D[N/3],D[N/2],D[N-1])+1;
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	int d[100001]={0,};
	cin>>n;
	d[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+1;
		if(i%2==0&&d[i]>d[i/2]+1) d[i]=d[i/2]+1;//���� ���϶��� update 
		if(i%3==0&&d[i]>d[i/3]+1) d[i]=d[i/3]+1;//���� ���϶��� update
		
	}
	cout<<d[n];
	
	return 0;
} 
//D[N]=N�� 1�θ���� �ּҿ��� Ƚ��.
/*���� ������
1. X�� 3���� ������ �������� 3���� ������.
N->N/3~~~>1�θ���� D[N/3]+1
2. X�� 2�� ������ �������� 2�� ������.
N->N/2~~~>1�θ���� D[N/2]+1
3. 1�� ����. 
N->N-1 1+D[N-1]
*/ 
/*
int go(int n){//top-down ����� ����(���) 
	if(n==1) return 0;
	if(d[n]>0) return d[n];
	d[n]=go(n-1) +1;
	if(n%2==0){
		int temp=go(n/2)+1;
		if(d[n]>temp) d[n]=temp;
	}
	if(n%3==0){
		int temp=go(n/3)+1;
		if(d[n]>temp) d[n]=temp;
	}
	return d[n];
}
*/
