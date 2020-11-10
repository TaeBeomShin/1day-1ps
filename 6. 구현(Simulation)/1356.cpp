#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,N;cin>>N;
	a="NO";
	if(N!="1"){
		for(int i=0;i<N.length();i++){
			int r=1,l=1;
			for(int j=0;j<i;j++) l*=N[j]-'0';
			for(int j=i;j<N.length();j++) r*=N[j]-'0';
			if(r==l) a="YES";
		}
	}
	cout<<a;
}
