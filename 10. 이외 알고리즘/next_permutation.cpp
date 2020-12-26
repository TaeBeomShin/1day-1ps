#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[4]={1,2,3,4};
	do{
		for(int i=0;i<4;i++) cout<<a[i]<<" ";
		cout<<"\n";
	}while(next_permutation(a,a+4));
	
	vector<int> b={1,2,3,4};
	
	do{
		for(int i=0;i<4;i++) cout<<b[i]<<" ";
		cout<<"\n";
	}while(next_permutation(b.begin(),b.end()));
}
