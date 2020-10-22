#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main(){
	fastio;
	int n,m;cin>>n>>m;
	set <string> v1,v2,intersect;
	std::vector<string>::iterator it, ls; 
	string temp;
	
	while(n--&&cin>>temp) v1.insert(temp);
	while(m--&&cin>>temp) v2.insert(temp); 
	
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),inserter(intersect,intersect.begin()));
	
	 for (it = intersect.begin(); it != intersect.end(); ++it) 
        cout <<*it<<"\n";
}

