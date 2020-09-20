#include<bits/stdc++.h>
using namespace std;

int buildings[80001];
int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++) cin>>buildings[i];
	
	stack<int> s;

	long long result=0;
	for(int i=0;i<n;i++){
		while(!s.empty()&&s.top()<=buildings[i]) s.pop();
		s.push(buildings[i]);
		result+=s.size()-1;
	}
	cout<<result;
}
