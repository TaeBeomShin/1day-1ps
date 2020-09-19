#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s;
	int k; cin>>k;
	while(k--){
		int num;cin>>num;
		if(num!=0) s.push(num);
		else s.pop();
	}
	int sum=0;
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	cout<<sum;
}
