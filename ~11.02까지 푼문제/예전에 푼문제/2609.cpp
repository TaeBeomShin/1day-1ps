#include<iostream>

using namespace std;

int gcd(int n,int m){
	while(m!=0){
		int r=n%m;
		n=m;
		m=r;
	}
	return n;
}
int main(){
	int N,M;
	cin>>N>>M;
	
	cout<<gcd(N,M)<<"\n"<<N/gcd(N,M)*M;
	//�ִ�����, ��Ŭ���� ȣ���� �̿�����!
	//�ּҰ���� = ������ �ִ������� ���� ��� �ִ������� ��~!
	return 0;
}
