#include<iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//�������� �̿�� �޸� �ʰ� �߻�. 
	//��������� �̿��Ѵ�.
	int N;
	cin>>N;
	int A[10001]={0,};
	
	int temp;
	
	for(int i=1;i<=N;i++){
		cin>>temp;
		A[temp]+=1;
	}
	
	for(int i=1;i<=10000;++i){
		for(int j=0;j<A[i];++j)
			cout<<i<<"\n";
	}
	
	return 0;
}
