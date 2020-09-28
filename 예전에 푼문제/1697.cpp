#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n,k;
int dist[100001];
int main(){
	fastio;
	cin>>n>>k;

	queue<int> Q;
	Q.push(n);
	dist[n]=1;
	
	if(n==k){
		cout<<0;
		return 0;
	}
	
	int count=0;
	int mn=200001;
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		int arr[3]={cur+1,cur-1,cur*2};
		
		for(int i=0;i<3;i++){
			int next=arr[i];
			if(next<0||next>100000) continue;//범위를 벗어나면.
			if(dist[next]>0) continue;//이미 방문했다면.
			if(next==k){
				mn=min(mn,dist[cur]);
				count++;
			}
			Q.push(next); 
			dist[next]=dist[cur]+1;
		}
	}
	cout<<mn<<"\n"<<count;
}
