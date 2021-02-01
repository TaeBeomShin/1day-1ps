#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	
	vector<int> v(2*n);
	for(int i=0;i<2*n;i++) cin>>v[i];
	
	sort(v.begin(),v.end());
	
	int maxnum=0;
	
	for(int i=0;i<n;i++){
		if(maxnum<v[i]+v[2*n-i-1]){
			maxnum=v[i]+v[2*n-i-1];
		}
	} 
	cout<<maxnum;
}
