#include<bits/stdc++.h>
using namespace std;

int n,q;
int arr[1000001]={0,};
int psum[1000001]={0,};
int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		psum[i+1]=psum[i]^arr[i];
	}
	
	int ans=0;
	for(int i=0;i<q;i++){
		int l,r;cin>>l>>r;
		ans^=(psum[r]^psum[l-1]);
	}
	
	cout<<ans;
}
