#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	long long sum=1;
	for(int i=1;i<=n;i++){
		if(n<=sum){
			cout<<i;
			break;
		}
		sum=sum+6*i;
	}
}
