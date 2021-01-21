#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	
	int ans=-1;
	for(int i=0;i<n/2;i++){
		if((n-2*i)%5==0){
			ans=i+(n-2*i)/5;
			break;
		}
	}
	cout<<ans;
}
