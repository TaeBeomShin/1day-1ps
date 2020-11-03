#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c=0;
	cin>>n;
	while(n--){
		string w;cin>>w;
		stack<char> S;
		for(int i=0;i<w.length();i++) (!S.empty()&&w[i]==S.top())?S.pop():S.push(w[i]);
		if(S.empty()) c++;
	}
	cout<<c;
}
