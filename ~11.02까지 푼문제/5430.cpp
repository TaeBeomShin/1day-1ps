#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		string s; cin>>s;
		int n; cin>>n;
		int A[n+1]={};
		string num; cin>>num;
		for(int i=1;i<=n;i++) A[i]=num[2*i-1]-'0';
		for(int i=1;i<=n;i++) cout<<A[i]<<" ";
		cout<<"\n";
	}
}
