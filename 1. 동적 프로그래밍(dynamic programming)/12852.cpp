#include<bits/stdc++.h>
using namespace std;

int dir[3]={3,2,1};
int dist[1000001];
int before[1000001];
int main(){
	int n;cin>>n;
	queue<int> Q;
	Q.push(n);
	dist[n]=1;
	before[n]=-1;
	if(n==1){
		cout<<1;
		return 0;
	}
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		
		for(int i=0;i<3;i++){
			int next=cur;
			if(i<2&&i%dir[i]==0) next=next/dir[i];
			else next=next-dir[i];
			if(next<1) continue;
			if(dist[next]>0) continue;
			if(next==1){
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
				cout<<1;
				return 0;
			}
			before[next]=cur;
			Q.push(next);
			dist[next]=dist[cur]+1;
		}
	}
}
