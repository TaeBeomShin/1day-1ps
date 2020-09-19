#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int main(){
	fastio;
	int n;cin>>n;	
	int array[n];
	stack<int> s;
	for(int i=0;i<n;i++) cin>>array[i];
	reverse(array,array+n);
	for(int i=0;i<n;i++) s.push(array[i]);
	
	int sum=0;
	int j=0;
	while(!s.empty()){
		int num=s.top();
		int count=0;
		for(int i=j;i<n;i++){
			if(num<array[i]) break;
			else if(num>array[i]) count++;
		}
		sum+=count;
		s.pop();
		j++;
	}
	cout<<sum;
}
