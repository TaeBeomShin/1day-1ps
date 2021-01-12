#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n,t;cin>>t;
	while(t--){
		cin>>n;
		priority_queue<int,vector<int>,greater<int>> minq;
		priority_queue<int> maxq;
		for(int i=0;i<n;i++){
			char oper;int num;cin>>oper>>num;
			if(oper=='I'){
				minq.push(num);
				maxq.push(num);
			}
			else{
				if(num==-1){
					if(minq.empty()) continue;
					if(minq.top()==maxq.top()) maxq.pop();
					minq.pop();
				}else{
					if(maxq.empty()) continue;
					if(minq.top()==maxq.top()) minq.pop();
					maxq.pop();
				}
			}
			if(maxq.top()<minq.top()){
				while(!minq.empty()) minq.pop();
				while(!maxq.empty()) maxq.pop();
			}
		}
		if(!maxq.empty()) cout<<maxq.top()<<" "<<minq.top()<<"\n";
		else cout<<"EMPTY\n";
	}
}
