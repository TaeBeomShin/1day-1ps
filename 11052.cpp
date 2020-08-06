#include<iostream>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);

using namespace std;

int main(){
//D[N]=D[N-i]+P[i];
//D[N]=min(D[N-i]+P[i]) 1<=i<=N -> N*O(N^2)
	fastio
	int N;
	cin>>N;
	int D[N+1]={0,};
	int P[N+1]={0,};
	
	for(int i=1;i<=N;i++){
		cin>>P[i];
		D[i]=P[i];
	}
	//�ּڰ��� ���ϱ�����, D[i]�� �̸� �����س��°� �߿�����. 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			D[i]=min(D[i],D[i-j]+P[j]);
		}
	}
	
	cout<<D[N]<<"\n";
	
	return 0;
}
