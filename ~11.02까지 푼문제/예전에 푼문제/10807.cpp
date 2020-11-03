#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int num[201];
int main(){
	fastio;
	
	int n,v;
	cin>>n;
	int number;
	for(int i=0;i<n;i++){
		cin>>number;
		num[number+100]++;
	}
	
	cin>>v;
	
	cout<<num[v+100];
}
