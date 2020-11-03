#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int n=abs(a)+abs(b);
	if(n<=c&&n%2==c%2) cout<<"YES";
	else cout<<"NO";
}
