#include<bits/stdc++.h>
using namespace std;

int A[101][101];
int B[101][101]; 
int main(){
	int n,m;cin>>n>>m;
	//n*m ũ���� ��İ� m*nũ���� ����� �־������� ������� ���ϴ� ���α׷�
	//n,m�� 100���� �����Ƿ� for������ �̿��ؼ� ������.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[i][j];
		}
	}
	
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			cin>>>B[i][j];
		}
	}
}
