#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	string s;cin>>s;
	fastio;
	
	int first=s[0];int prenum=s[0];
	int count=0;
	for(int i=1;i<s.length();i++){
		if(prenum!=s[i]&&first!=s[i])
			count++;
		prenum=s[i];
	}
	cout<<count;
}

