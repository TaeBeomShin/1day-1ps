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
			n++;//������ ������ ������Ų��(== n�� ������.) 
		}
		count=ans;
	}
	cout<<count;
}
