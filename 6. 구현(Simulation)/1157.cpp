#include<bits/stdc++.h>
using namespace std;

int alpha[26];
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
		alpha[toupper(s[i])-'A']++;
	
	int maxn=0;
	int maxi;
	for(int i=0;i<26;i++){
		if(alpha[i]>maxn){
			maxn=alpha[i];
			maxi=i;
		}
	}
	bool check=false;
	for(int i=0;i<26;i++)
		if(i!=maxi&&maxn==alpha[i]) check=true;
	
	char ans='A'+maxi;
	if(check) cout<<"?";
	else cout<<ans;
}
