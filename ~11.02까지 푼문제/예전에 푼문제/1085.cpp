#include<iostream>

using namespace std;

int min(int a,int b){
	return (a<=b)?a:b;
}
int main(){
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	
	cout<<min(min(x,y),min(w-x,h-y));
	return 0;
}
