#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;int b; cin>>a>>b;
	sort(a.begin(),a.end());
	int ans=-1;
	do{
		if(a[0]=='0'||stoi(a)>=b) continue;
		ans=stoi(a);
	}while(next_permutation(a.begin(),a.end()));
	
	cout<<ans;
}
