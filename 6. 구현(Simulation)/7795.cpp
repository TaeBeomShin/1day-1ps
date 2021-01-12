#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		vector<int> A(n),B(m);
		for(int i=0;i<n;i++) cin>>A[i];
		for(int i=0;i<m;i++) cin>>B[i];
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		int count=0;
		for(int i=0;i<n;i++){
			int a=A[i];
			for(int j=0;j<m;j++){
				if(a>B[j]) count++;
				else break;
			}
		}
		cout<<count<<"\n";
	}
	
}
