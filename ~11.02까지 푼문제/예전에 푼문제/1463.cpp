#include<iostream>

using namespace std;

int main(){
//식 D[N]=min(D[N/3],D[N/2],D[N-1])+1;
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	int d[100001]={0,};
	cin>>n;
	d[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]+1;
		if(i%2==0&&d[i]>d[i/2]+1) d[i]=d[i/2]+1;//최적 값일때만 update 
		if(i%3==0&&d[i]>d[i/3]+1) d[i]=d[i/3]+1;//최적 값일때만 update
		
	}
	cout<<d[n];
	
	return 0;
} 
//D[N]=N을 1로만드는 최소연산 횟수.
/*연산 세가지
1. X가 3으로 나누어 떨어지면 3으로 나눈다.
N->N/3~~~>1로만들기 D[N/3]+1
2. X가 2로 나누어 떨어지면 2로 나눈다.
N->N/2~~~>1로만들기 D[N/2]+1
3. 1을 뺀다. 
N->N-1 1+D[N-1]
*/ 
/*
int go(int n){//top-down 방식의 구현(재귀) 
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
