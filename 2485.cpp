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
//	각 숫자의 간격을 저장한다.
//	숫자를 받으면서 최대공약수를 갱신한다.
//	최대공약수로 몫을 나누고 2이상일때에 대해서 몫을 1을밴 수를 더해준다. 
	int temp,min;
	cin>>temp;
	for(int i=0;i<N-1;i++){
		int a=temp;
		cin>>temp;
		tree[i]=temp-a;//0~N-2까지 간격저장함. 
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
