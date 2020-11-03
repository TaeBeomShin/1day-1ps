#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	int t;cin>>t;
	fastio;
	while(t--){
		int n;cin>>n;
		int min=1000001;
		int max=-1000001;
		for(int i=0;i<n;i++){
			int num;cin>>num;
			if(num>max) max=num;
			if(num<min) min=num;
		}
		cout<<min<<" "<<max<<"\n";
	}
}
