#include<bits/stdc++.h>
using namespace std;

int A[501];
int rain[501];
int main(){
	int m,n;cin>>m>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	
	int sum=0;
	for(int i=0;i<n;i++){
		int left=0,right=0;
		for(int j=0;j<i;j++){
			left=max(A[j],left);
		}
		for(int j=i;j<n;j++){
			right=max(A[j],right);
		}
		rain[i]=max(min(left,right)-A[i],0);
		sum+=rain[i];
	}
	cout<<sum;
}
