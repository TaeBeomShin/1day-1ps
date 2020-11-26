#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;cin>>n>>k;
	int count=0;
	if(n>k){
		int ans;
		for(ans=0;;ans++){
			count=0;
			int temp=n;
			
			while(temp){
				if(temp%2)count++;
				temp/=2;
			}
			if(count<=k) break;
			n++;//물병의 개수를 증가시킨다(== n이 증가함.) 
		}
		count=ans;
	}
	cout<<count;
}
