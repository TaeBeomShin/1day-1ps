#include<bits/stdc++.h>
using namespace std;
/*
	BOJ1051 ���� ���簢��
	
	������ ����. ����(���ھȿ��� �ִ밪 ã��..)
	- �������� ũ�⸦ �÷����鼭 �����ϴ� �ִ� ���簢���� ���Ѵ�. 
*/
int main(){
	int m,n;cin>>n>>m;
	
	int arr[n][m];
	int num=max(m,n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int size=1;size<num;size++){
				if(i+size>=n||j+size>=m) continue;
				if(arr[i][j]==arr[i+size][j]&&arr[i+size][j]==arr[i][j+size]&&arr[i][j+size]==arr[i+size][j+size]){
					ans=max(ans,size+1);
				}
			}
		}
	}
	cout<<ans*ans;
} 
