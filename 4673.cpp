#include<bits/stdc++.h>
using namespace std;

bool num[10001]={0,}; 
void d(int n){//
	int sum=n;
	if(n>10000) return;
	while(n!=0){
		sum+=n%10;
		n=n/10;
	}
	if(sum>10000) return;
	num[sum]=true;
	d(sum);
}
int main(){
	for(int i=1;i<=10000;i++){
		d(i);
	}
	for(int i=1;i<=10000;i++){
		if(num[i]==false) cout<<i<<"\n";
	}
}
