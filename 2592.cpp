#include<iostream>
#include<algorithm>

using namespace std;

int deca[101];
int main(){
	//��հ� �ֺ��� ���ϴ� ���α׷� �ۼ��ϱ�.
	//input���� 1000���� ���� 10�� ���-> 10���� �������� �ε������ؼ� �����ϸ� ��.
	
	int sum=0;
	for(int i=0;i<10;i++){
		int temp;
		cin>>temp;
		sum+=temp/10;
		deca[temp/10]++;
	}
	
	int index;
	int max=0;
	
	for(int i=0;i<100;i++){
		if(deca[i]>max){
			max=deca[i];
			index=i;
		}
	}
	cout<<sum<<"\n"<<index*10;
		
	return 0;
}
