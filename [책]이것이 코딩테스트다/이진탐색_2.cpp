#include<bits/stdc++.h>
using namespace std;
 
int arr[1000001];
int arr2[100001];

int binary_search(int arr[],int t,int s,int e){
	if(s>e) return false;
	int m=(s+e)/2;
	while(s<=e){
		if(arr[m]==t) return true;
		else if(arr[m]>t) return binary_search(arr,t,s,m-1);
		else return binary_search(arr,t,m+1,e);
	}
	return false;
}

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int m;cin>>m;
	for(int i=0;i<m;i++) cin>>arr2[i];
	for(int i=0;i<m;i++){
		if(binary_search(arr,arr2[i],0,n-1)) cout<<"yes\n";
		else cout<<"no\n";
	}
}
