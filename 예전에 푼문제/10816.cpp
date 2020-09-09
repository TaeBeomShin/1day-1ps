#include<iostream>
#include<algorithm> 

using namespace std;

//int upperbound(int* array,int length,int value){
//	int count=0;
//	int s=0,e=length-1;
//	
//	while(e-s>=0){//�� �ε����� ���������� ����. 
//		int mid=(s+e)/2;
//		
//		if(array[mid]>value){
//			e=mid;
//		}
//		else{
//			s=mid+1;
//		}
//	}
//	return e;
//}
//
//int lowerbound(int* array,int length,int value){
//	int count=0;
//	int s=0,e=length-1;
//	
//	while(e-s>=0){//�� �ε����� ���������� ����. 
//		int mid=(s+e)/2;
//		
//		if(array[mid]>=value){
//			e =mid;
//		}
//		else{
//			s=mid+1;
//		}
//	}
//	return e;
//}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
//�Է°� n 50��,  ���� ī���� �� 1000��,
//�Է°� m 50��, ���� ī���� �� 1000��. 
	int N,M;
	cin>>N;
	int Ncard[N+1];
	for(int i=0;i<N;i++) cin>>Ncard[i];
	
	cin>>M;	
	int Mcard[M+1];
	for(int i=0;i<M;i++) cin>>Mcard[i];
	sort(Ncard,Ncard+N);
//std::sort �Լ��� lower_bound, upper_bound�� �̿��Ѵ�. 
//	for(int i=0;i<M;i++){
//		cout<<upperbound(Ncard,N,Mcard[i])-lowerbound(Ncard,N,Mcard[i])<<" ";
//	}
	for(int i=0;i<M;i++){
		int value = Mcard[i];
		int low=(lower_bound(Ncard,Ncard+N,value)-Ncard+1);
		int upper=(upper_bound(Ncard,Ncard+N,value)-Ncard+1);
		cout<<upper-low<<" ";
	}
	
	return 0;
}
