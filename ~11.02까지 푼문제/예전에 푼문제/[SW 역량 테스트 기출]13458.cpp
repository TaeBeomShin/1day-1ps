#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	int N,B,C;
	scanf("%d",&N);
	
	int A[N+1]; 
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);
	scanf("%d %d",&B,&C);
	//최소환의 감독관수 구하기
	//각 시험장에 총 감독관 1명씩을 고정적으로 있음
	//남은 인원들을 부감독관으로 감독해야함.
	//필요한 부감독관의 수 (A[i]-B)/C
	
	long long sum=N; //총 필요한 감독관수, 각 시험장에 총감독관이 한명씩 필요 하ㅇ므로.
	 
	
	for(int i=1;i<=N;i++){
		if(A[i]-B>0)
			if((A[i]-B)%C==0)// 나머지가 0일때 
				sum+=(A[i]-B)/C;
			else//나머지가 0이 아닐때. 
				sum+=(A[i]-B)/C+1;
	}
	
	printf("%lld",sum);
	return 0; 
}
