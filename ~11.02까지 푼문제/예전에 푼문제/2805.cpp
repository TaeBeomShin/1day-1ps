#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
//�־��� M�� ���� ������ ���� ���ϴ� binary search. 
int main(){
	
	cin>>N>>M;
	
	int tree[N];
	int max=0;
	for(int i=0;i<N;i++){
		cin>>tree[i];
		if(tree[i]>max) max=tree[i];
	}
	sort(tree,tree+N);
	
	
	int start=0;
	int end=max;
	int mid;
	int result=0;
	
	long long sum=0;
	
	while(true){
		mid=(start+end)/2;
		//������ �߶󳻰� ���� ���Ѵ�.
		sum=0;
		for(int i=0;i<N;i++){
			if(tree[i]-mid>0) sum+=tree[i]-mid;
		}
		//�߶� �� ������ ���̸� �������� Ž���� �Ѵ�.
		//1.�߶� ������ ���̰� M���� ������ 
		if(sum==M){
			result=mid;
			break;
		}
		//2.�߶� ������ ���̰� M������ ũ��
		else if(sum>M){
			result=mid;
		 	start=mid+1;
		 }
		//3.�߶� ������ ���̰� M������ ������ 
		else{
			end=mid-1;
		}
		if(start>end){
			break;
		}
	}
	cout<<result;
	return 0;
}
