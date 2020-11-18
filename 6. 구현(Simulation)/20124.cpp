#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
int main(){
	fastio;
	int n;cin>>n;
	int maxnum=0;
	string maxp;
	
	while(n--){
		int t;string h;cin>>h>>t;
		if(t>maxnum){
			maxnum=t;
			maxp=h;
		}else if(t==maxnum){
			if(maxp.compare(h)>0){
				maxp=h;
			}
		}
	}
	cout<<maxp;
}
