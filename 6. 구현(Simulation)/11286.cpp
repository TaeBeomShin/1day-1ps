#include<bits/stdc++.h>
#define P pair<int,int>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	priority_queue<P,vector<P>,greater<P>> Q;
	
	for(int i=0;i<n;i++){
		int num;cin>>num;
		if(num==0){
			if(Q.empty()){
				cout<<"0\n";
				continue;	
			}
			 cout<<Q.top().second<<"\n";
			 Q.pop();
		}else{
			Q.push({abs(num),num});
		}
	}
}
