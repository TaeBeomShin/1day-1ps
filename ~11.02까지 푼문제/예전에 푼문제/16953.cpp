#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

int a,b;
int dist[MAX];
int main(){
	cin>>a>>b;
	//a->b로 바꾸는데 필요한 연사의 최솟값.
	
	queue <int> Q;
	Q.push(a);
	dist[a]=1;
	
	while(!Q.empty()){
		int cur=Q.front(); Q.pop();
		if(cur==b) break;
		int arr[2]={cur*2,cur*10+1};
		
		for(int i=0;i<2;i++){
			int next=arr[i];
			if(next>MAX) continue;
			if(dist[next]) continue;
			Q.push(next);
			dist[next]=dist[cur]+1;
		}
	}
	cout<<dist[b];
	
	return 0;
}
