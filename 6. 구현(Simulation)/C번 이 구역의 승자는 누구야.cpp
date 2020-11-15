#include<bits/stdc++.h>
using namespace std;
int alpha[26]={3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1};

int main(){
	string S;cin>>S;
	int sum=0;
	for(int i=0;i<S.length();i++) sum+=alpha[S[i]-'A'];	
	(sum&1)?cout<<"I'm a winner!":cout<<"You're the winner?";
}
