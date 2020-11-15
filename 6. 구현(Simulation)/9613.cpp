#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	int temp;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
int main(){
	int t;cin>>t;
	while(t--){
		long long sum=0,n;cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				sum+=gcd(v[i],v[j]);
		cout<<sum<<"\n";
	}
}
