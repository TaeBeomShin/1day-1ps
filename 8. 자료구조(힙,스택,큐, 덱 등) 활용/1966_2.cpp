#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,t;cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> x(n),y(n);
		for(int k,i=0;i<n;i++){
			cin>>k;
			x[i]=y[i]=k;
		}
		sort(y.begin(),y.end());
		for(int a=0,i=0,e=n-1;;i=(i+1)%n){
			if(x[i]==y[e]){
				a++,e--;
				if(i==m){
					cout<<a<<"\n";
					break;
				}
			}
		}
	}
}
