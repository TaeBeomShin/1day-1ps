#include<iostream>

using namespace std;

int coin[11];
int main(){
	int n,k;
	cin>>n>>k;
	//�׸��� �˰���.
	//K���� ���� �� �� ���� ū ���� ���� ������ ���Խ�Ų��(k���� �� �� ��ŭ ����& �ݺ�)
	for(int i=1;i<=n;i++){
		cin>>coin[i];
	}
	
	int count=0;
	while(k!=0){
		for(int i=1;i<=n;i++){
			if(k<coin[i]){
				count+=k/coin[i-1];
				k=k%coin[i-1];
				break;
			}else if(i==n){
				count+=k/coin[i];
				k=k%coin[i];
			}
		}
	}
	
	cout<<count;
	
	return 0;
}
