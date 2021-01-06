#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int t;cin>>t;
	while(t--){
		string s; cin>>s;
		stack <char> S;
		int left=0,right=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='('){
				S.push('(');
				left++;
			}
			else if(s[i]==')'){
				if(!S.empty()) S.pop();
				right++;	
			}
		}
		(left!=right||!S.empty())?cout<<"NO\n":cout<<"YES\n";
	}
}
