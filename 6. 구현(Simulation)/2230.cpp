#include<bits/stdc++.h>
using namespace std;
/*
	��������.
	
	�迭�� �����ؼ� �� ���� ���� m���� ũ�ų� ������ start�� �ø���
	������ end�� �ø���.
	
	���� �ּڰ��� ��ȯ�Ѵ�. 
*/
int main(){
	cin.tie(0);
	int n,m;cin>>n>>m;
	
	int arr[n]={0,};	
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	
	int start=0,end=0;
	int sum=2*1e9+1e8;
	int ans=2*1e9+1e8;
	while(start<=end&&end<n){
		sum=arr[end]-arr[start];
//		cout<<start<<" "<<end<<" "<<sum<<"\n";
		if(sum>=m){
			ans=min(ans,sum);
			if(start==end) end++;
			start++;
		}else{
			end++;
		}
	}
	cout<<ans;
}

