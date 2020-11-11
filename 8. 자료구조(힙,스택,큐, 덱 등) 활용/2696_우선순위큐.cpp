#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
 
int main(){
	fastio;
	int t;cin>>t;
	
	while(t--){
		int m;cin>>m;
		//우선순위 큐 2개이용, 하나는 최대힙// 하나는 최소힙. 
		priority_queue <int,vector<int>> Q1;//최대힙 
		priority_queue <int,vector<int>,greater<int>> Q2;//최소힙 
		vector<int>ans;
		//중앙값의 개수 출력. 
		if(m%2==1) cout<<m/2+1;
		else cout<<m/2;
		
		for(int _=1;_<=m;_++){
			int temp; cin>>temp;
			(Q1.size()>Q2.size())?Q2.push(temp):Q1.push(temp);
			if(!Q1.empty()&&!Q2.empty()&&Q1.top()>Q2.top()){//pq1이 항상 더 작도록만든다.
				int a=Q1.top();Q1.pop();
				int b=Q2.top();Q2.pop();
				Q1.push(b),Q2.push(a);
			}
			if(_&1)ans.push_back(Q1.top());
		}
		for(int i=0;i<ans.size();i++){
			if(i%10==0)cout<<"\n";
			cout<<ans[i]<<" "; 
		}
		cout<<"\n";
	}
}
