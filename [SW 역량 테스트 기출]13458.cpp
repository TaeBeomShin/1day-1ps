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
	//�ּ�ȯ�� �������� ���ϱ�
	//�� �����忡 �� ������ 1���� ���������� ����
	//���� �ο����� �ΰ��������� �����ؾ���.
	//�ʿ��� �ΰ������� �� (A[i]-B)/C
	
	int sum=N; //�� �ʿ��� ��������, �� �����忡 �Ѱ������� �Ѹ� �ʿ� �Ϥ��Ƿ�.
	 
	
	for(int i=1;i<=N;i++){
		if(A[i]-B>0)
			if((A[i]-B)%C==0)// �������� 0�϶� 
				sum+=(A[i]-B)/C;
			else//�������� 0�� �ƴҶ�. 
				sum+=(A[i]-B)/C+1;
	}
	
	printf("%d",sum);
	return 0; 
}
