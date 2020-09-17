#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int num[1000001];
int main(){
	fastio;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>num[i];
	
	sort(num,num+n);
	
	for(int i=0;i<n;i++) cout<<num[i]<<"\n";
	
	return 0;
}
