#include<bits/stdc++.h>
using namespace std;

int n,t;
int belt1[205],belt2[205],belt3[205];
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>belt1[i];
	for(int i=1;i<=n;i++) cin>>belt2[i];
	for(int i=1;i<=n;i++) cin>>belt3[i];
	
	while(t--){
		int temp1=belt1[n],temp2=belt2[n],temp3=belt3[n];
		
		for(int i=n-1;i>=1;i--){
			belt1[i+1]=belt1[i];
			belt2[i+1]=belt2[i];
			belt3[i+1]=belt3[i];
		}
		belt2[1]=temp1;
		belt3[1]=temp2;
		belt1[1]=temp3;
	}
	
	for(int i=1;i<=n;i++) cout<<belt1[i]<<" ";
	puts("");
	for(int i=1;i<=n;i++) cout<<belt2[i]<<" ";
	puts("");
	for(int i=1;i<=n;i++) cout<<belt3[i]<<" ";
}
