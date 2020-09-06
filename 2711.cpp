#include<iostream>


using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int pos;
		string word;
		cin>>pos>>word;
		cout<<word.substr(0,pos-1)<<word.substr(pos,word.length())<<"\n";
	}
	
	return 0;
}
