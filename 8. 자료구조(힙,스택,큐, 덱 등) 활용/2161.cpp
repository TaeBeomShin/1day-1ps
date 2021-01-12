#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	deque<int> Q;
	
	for(int i=1;i<=n;i++) Q.push_back(i);
	
	while(Q.size()!=1){
		int temp=Q.front();cout<<temp<<" ";
		Q.pop_front();
		temp=Q.front();Q.pop_front();
		Q.push_back(temp);
	}
	cout<<Q.front();
}
