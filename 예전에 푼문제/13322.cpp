#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string S;
	cin>>S;
	/*
	string temp;
	vector<string> v;
	vector<int> prefix;
	for(int i=0;i<S.size();i++){
		temp=S.substr(0,i+1);
		v.push_back(temp);
		prefix.push_back(i);
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++){
		//cout<<v[i]<<"\n";
		cout<<prefix[i]<<"\n";
	}
	*/
	
	for(int i=0;i<S.size();i++) cout<<i<<"\n";
	return 0;
	//접두사 배열이 없는 이유. 
}
