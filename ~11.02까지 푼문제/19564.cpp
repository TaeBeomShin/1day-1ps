#include<bits/stdc++.h>
using namespace std;

int main(){
	string S;cin>>S;
	int count=0;
	for(int i=0;i<S.length();i++){
		if(S[i]<S[i+1])	count++;
	}
	cout<<S.length()-count;
}
