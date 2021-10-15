#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	
	while(t--){
		int n;cin>>n;
		int arr[n+1]={0,};
		int psum[n+1]={0,};
		int maxNum=-1e9;
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
			psum[i+1]=psum[i]+arr[i];
		}
		
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int csum=psum[j]-psum[i];
				if(csum>maxNum){
					maxNum=csum;
				}
			}
		}
		cout<<maxNum<<"\n";
	}
}
