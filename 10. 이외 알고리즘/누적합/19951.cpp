#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n,m;
int arr[100002]={0,};
int asum[100002]={0,};
int main(){
	fastio;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	//������ �ޱ� 
	for(int i=1;i<=m;i++){
		int a,b,k;cin>>a>>b>>k;
		asum[a]+=k;
		asum[b+1]-=k;
	}
	
	//������ ����� 
	for(int i=0;i<n;i++){
		asum[i+1]+=asum[i];
//		cout<<asum[i+1]<<" ";
	}
//	cout<<"\n";
	
	//���� ������ �迭�� ��������ϱ�
	
	for(int i=1;i<=n;i++){
		arr[i]+=asum[i];
		cout<<arr[i]<<" ";
	}
}
