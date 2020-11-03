#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	string S;
	cin>>S;
	
	string temp;
	vector<string> v;
	vector<int> prefix;
	for(int i=1;i<=S.size();i++){
		temp=S.substr(S.size()-i,i);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";;
	}
	
	return 0;
}
