#include<iostream>

using namespace std;

int tree[100001];

int gcd(int a,int b){
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N;
	cin>>N;
//	�� ������ ������ �����Ѵ�.
//	���ڸ� �����鼭 �ִ������� �����Ѵ�.
//	�ִ������� ���� ������ 2�̻��϶��� ���ؼ� ���� 1���� ���� �����ش�. 
	int temp,min;
	cin>>temp;
	for(int i=0;i<N-1;i++){
		int a=temp;
		cin>>temp;
		tree[i]=temp-a;//0~N-2���� ����������. 
		if(i==0) min=tree[i];
		else if(min>gcd(tree[i-1],tree[i])) min=gcd(tree[i-1],tree[i]);
	}

	int sum=0;
	for(int i=0;i<N-1;i++){
		tree[i]=tree[i]/min;		
		if(tree[i]>1) sum+=tree[i]-1;
	}
	
	cout<<sum;
	return 0;
}
