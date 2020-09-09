#include<iostream>
#include<algorithm>

using namespace std;

int deca[101];
int main(){
	//평균과 최빈값을 구하는 프로그램 작성하기.
	//input값은 1000보다 작은 10의 배수-> 10으로 나눈값을 인덱스로해서 저장하면 됨.
	
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
