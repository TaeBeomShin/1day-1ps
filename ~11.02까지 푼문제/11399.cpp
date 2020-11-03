#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int A[1001]={0,};
int main(){
	fastio;
	int n,sum=0;cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	sort(A,A+n);
	for(int i=0;i<n;i++) sum+=A[i]*(n-i);
	cout<<sum;
}	
