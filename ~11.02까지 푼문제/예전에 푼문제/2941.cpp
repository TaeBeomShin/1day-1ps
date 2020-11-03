#include<bits/stdc++.h>
using namespace std;
int main(){
	string word;cin>>word;
	int count=0;
	for(int i=0;i<word.length()-1;i++){
		string temp=word.substr(i,2);
		string temp2=word.substr(i,3);
		if(temp2=="dz="){
			count+=2;
			i++;
		}
		else if(temp=="c="||temp=="c-"||temp=="d-"||temp=="lj"||temp=="nj"||temp=="s="||temp=="z=" ){
			count++;
			i++;
		}
	}
	cout<<word.length()-count;
}
