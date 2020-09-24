#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n,k;
int dist[100001];
int before[100001];

int main(){
	cin>>n>>k;
	
	queue<int> Q;
	Q.push(n);
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		if(cur==k){
			cout<<dist[cur]<<"\n";
			stack <int> S;
			while(cur!=n){
				S.push(cur);
				cur=before[cur];
			}
			S.push(n);
			while(!S.empty()){
				cout<<S.top()<<" ";S.pop();
			}
			return 0;
		}
		for(int next:{cur+1,cur-1,cur*2}){
			if(next<0||next>100000) continue; //���� ���̶��. 
			if(dist[next]) continue; //�̹� �湮�� ���̶��.
			
			Q.push(next);
			dist[next]=dist[cur]+1;
			before[next]=cur; 
		}
	}

} 
