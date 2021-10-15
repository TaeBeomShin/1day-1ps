#include<bits/stdc++.h>
using namespace std;

int n,h;
int beforeSum[500003]={0,};
int pSum[500003]={0,};
int main(){
	cin>>n>>h;
	
	for(int i=0;i<n;i++){
		int height;cin>>height;
		if(i%2==0){
			beforeSum[1]+=1;
			beforeSum[height+1]-=1;
		}else{
			beforeSum[h-height+1]+=1;
		}
	}
	
	int ans=beforeSum[1],c=1;
	pSum[1]=beforeSum[1];
	for(int i=1;i<h;i++){
		pSum[i+1]=pSum[i]+beforeSum[i+1];
		if(pSum[i+1]<ans){
			ans=pSum[i+1];
			c=1;
		}else if(pSum[i+1]==ans){
			c++;
		}
	}
	cout<<ans<<" "<<c;
}
