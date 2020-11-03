#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main(){
	fastio;
	int n,m;string temp;cin>>n>>m;
	set <string> v1,v2; vector<string> v;
	
	while(n--&&cin>>temp) v1.insert(temp);
	while(m--&&cin>>temp) v2.insert(temp); 
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
	
	cout<<v.size()<<"\n";
	for(auto& name : v) cout<<name<<"\n";
}

