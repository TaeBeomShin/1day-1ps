#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;cin>>n>>m;
	
	
	int A[n]={0,},left=0,right=0;
	for(int i=0;i<n;i++){
		cin>>A[i];
		left=max(left,A[i]);
		right+=A[i];
	}
	
	// LEFT ��緹���� �ּ�ũ��(������ ����ū��)
	// RIGHT ��緹���� �ִ�ũ��(��� ��緹�̸� ��ģ��. 
	while(left<=right){
		int mid=(left+right)/2;
		
		int count=1,sum=0; 
		for(int i=0;i<n;i++){
			if(sum+A[i]<=mid){
				sum+=A[i];	
			}else{//sum�� �������� ��緹���� ũ�⸦ �Ѵ� ���. 
				sum=A[i];
				count++;
			}
		}
		if(count<=m){//��緹���� ������ �� ���� ���-> ũ�⸦ ���δ�. 
			right=mid-1; 
		}else{
			left=mid+1;
		}
	}
	cout<<left;
}
