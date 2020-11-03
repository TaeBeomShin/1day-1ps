#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define MAX 100050
using namespace std;

int A[MAX];
int fsum[MAX];
int bsum[MAX];

int main(){
	fastio;
	int n;cin>>n;
	int m=INT_MIN;
	
	for(int i=1;i<=n;i++) cin>>A[i];
	
	if(n==1){
		cout<<A[0]<<"\n";
  }
 	else{
		for(int i=1;i<=n;i++) fsum[i]=max(A[i],fsum[i-1]+A[i]);
		for(int i=n;i>=1;i--) bsum[i]=max(A[i],bsum[i+1]+A[i]);

		for(int i=1;i<=n;i++){
			if(m<fsum[i]){
				m=fsum[i];
			}
		}
		
		for(int i=1;i<=n;i++){
			m=max(m,fsum[i-1]+bsum[i+1]);
		}
		cout<<m<<"\n";
	}
	
	
}
