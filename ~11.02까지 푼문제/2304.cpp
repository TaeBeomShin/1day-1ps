#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int A[1001]={0,};
int B[1001]={0,};
int main(){
	int n;cin>>n;
	int m=0;
	for(int i=0;i<n;i++){
		int L,H;cin>>L>>H;
		A[L]=H;
		if(m<L) m=L;
	}
	for(int i=0;i<=m;i++){
		int left=0,right=0;		
		for(int j=0;j<i;j++) left=max(left,A[j]);
		for(int j=i;j<=m;j++) right=max(right,A[j]);
		B[i]=max(0,min(left,right)-A[i]);

	}
	int sum=0;
	for(int i=0;i<=m;i++) sum+=B[i]+A[i];
	
	cout<<sum;
}

