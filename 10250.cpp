#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int h,w,n;//h:ȣ���� ����, w: �� ���� ���,n: �� ��° �մ��ΰ�.
		cin>>h>>w>>n;
		//ä������ ����. 101 201 ... h01, 102,...
		int result=(n-1)/h+1+((n-1)%h+1)*100;
		cout<<result<<"\n"; 
	}
}
