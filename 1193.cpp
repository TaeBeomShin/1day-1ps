#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;cin>>x;
	int group,munja;
	for(int i=1;i<=x;i++){
		x=x-i;
		cout<<x-i<<"\n";
		if(x<0){
			group=i-1;
			munja=x+i;
			break;
		}
	}
}
