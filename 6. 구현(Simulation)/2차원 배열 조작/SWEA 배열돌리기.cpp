#include<bits/stdc++.h>
using namespace std;
/*
	SWEA 1961 - ���� �迭 ȸ 
	2���� �迭 �ٷ�� ������ 
	
	- 2���� �迭 �ٷ� ��, �������� 2���� �迭�� �ִ� �Լ��� ������ �� ��.(�޸� ��뷮 ����)
	- n�� ���̽��� �Ϲ�ȭ ��Ű��, �׸����� �׷�����.
	 
*/
int main(){
	int t;cin>>t;
	for(int c=1;c<=t;c++){
		int n;cin>>n;
		int arr[n][n]={0,};
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		cout<<"#"<<c<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<arr[n-1-j][i];
			cout<<" ";
			for(int j=0;j<n;j++) cout<<arr[n-1-i][n-1-j];
			cout<<" ";
			for(int j=0;j<n;j++) cout<<arr[j][n-1-i];
			cout<<"\n";
		}
	}
}
