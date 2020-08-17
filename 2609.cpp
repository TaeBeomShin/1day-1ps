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
	//최대공약수, 유클리드 호제법 이용했음!
	//최소공배수 = 각수를 최대공약수로 나눈 몫과 최대공약수의 곱~!
	return 0;
}
