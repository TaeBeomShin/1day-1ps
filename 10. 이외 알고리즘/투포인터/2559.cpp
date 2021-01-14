#include<bits/stdc++.h>
using namespace std;

int psum[100001]={0,};
int main(){
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		if(i==0){
			psum[i]=num;
			continue;	
		}
		psum[i]+=psum[i-1]+num;
	}
	
	int start=0,end=k;
	int sum=psum[k]-psum[0];
	
	for(int i=0;i<=n-k;i++)
		sum=max(sum,psum[end+i]-psum[start+i]);
	
	cout<<sum;
}
