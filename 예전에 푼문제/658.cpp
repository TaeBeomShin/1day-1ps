#include<iostream>

using namespace std;

bool sosu[1000001]={1,1};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	
	for(int i=2;i*i<=1000000;i++){//100���� ��Ʈ����
		for(int j=2*i;j<1000000;j+=i){
			sosu[j]=true;//���Ұ� 0�̸� �Ҽ��� �ƴϴ�. 
		}
	}
	while(cin>>n&&n!=0){
//�������� ����
//�� �Ҽ��� ������ ���� ��Ÿ����(������ 2���ƴ� �Ҽ��� ��� Ȧ����, 1�� �Ҽ��ƴ�.)
//���� �Ҽ����� �ϳ��� ����, ���� ���� �Ҽ����� �����Ѵ�.
//1. 1000000 ������ ���鿡 ���� �Ҽ����θ� �����ϴ� �迭�� ��������.
//2. sosu[j]=false�� �͵��� ��ȸ�ϸ鼭 �־��� ������ ���� sosu���� Ȯ���ϰ� ������ ����
		int num1=0,num2=0;
		for(int i=3;i<n;i++){
			if(!sosu[i]&&!sosu[n-i]){//�Ѵ� �Ҽ��ƴϸ�. 
				num1=i,num2=n-i;
				break;
			}
		}
		if(num1+num2==n){
			cout<<n<<" = "<<num1<<" + "<<num2<<"\n";
		}
		else{
			cout<<"Goldbach's conjecture is wrong.\n";
		}
 
	}

//	for(int i=1;i<100;i++){
//		cout<<i<<" "<<sosu[i]<<"\n";
//	}
	return 0;
}
