#include<bits/stdc++.h>
using namespace std;

int main(){
	int num=1;
	while(true){
		int l,p,n;cin>>l>>p>>n;
		if(l==0&&p==0&&n==0) break;
		int ans=min(n%p,l);
		cout<<"Case "<<num<<": "<<n/p*l+ans<<"\n";
		num++;
	}
	
}
