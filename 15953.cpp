#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

int first[100]={500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10};
int second[64]={512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<(first[a-1]+second[b-1])*10000<<"\n";
	}
	
	return 0;
}
