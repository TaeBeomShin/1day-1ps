#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		priority_queue<int> Q1;
		priority_queue<int,vector<int>,greater<int>>Q2;
		vector<int> ans;
		
		(n&1)?cout<<n/2+1:cout<<n/2;
		cout<<"\n";
		for(int _=1;_<=n;_++){
			int num;cin>>num;
			Q1.push(num);
			Q2.push(num);
			
			if(_&1){//È¦¼ö°¡ µÇ¸é.
				while(!Q1.empty()&&Q1.size()!=_/2+1){
					Q1.pop();
					if(Q1.size()==_/2+1) break;
				}
				while(!Q2.empty()&&Q2.size()!=_/2){
					Q2.pop();
					if(Q2.size()==_/2) break;
				}
				ans.push_back(Q1.top());
				if(Q1.top()<Q2.top()){
					cout<<Q1.top()<<" ";
				}
				else{
					cout<<Q2.top()<<" ";
				}
			}
		}
		cout<<"\n";
	}
}
