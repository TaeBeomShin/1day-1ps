#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int sum=0;
	string s; getline(cin,s);
	regex r(R"(\s*[\d]+\s*)");
	for(auto it=sregex_iterator(s.begin(),s.end(),r);it!=sregex_iterator();it++){
		sum+=stoi(it->str());
	}
	cout<<sum;
}
