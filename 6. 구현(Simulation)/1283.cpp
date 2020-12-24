#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

bool alpha[27];
int main(){
	fastio;
	int n;cin>>n;
	string s;
	for(int i=0;i<n;i++){
		getline(cin,s); 
		int idx;
		for(int j=0;j<s.length();j++){
			if(s[j]==' ') continue;
			if(!alpha[tolower(s[j])-'a']){
				idx=j;
				break;
			}
		}
		for(int j=0;j<s.length();j++){
			if(j==idx){
				cout<<"["<<s[j]<<"]";
				continue;
			}
			cout<<s[j];
		}
		cout<<"\n";
	}
}
