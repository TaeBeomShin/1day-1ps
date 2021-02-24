#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int arr[10]={0,};
		for(int i=0;i<10;i++) cin>>arr[i];
		sort(arr,arr+10);
		cout<<arr[7]<<"\n";
	}
}
