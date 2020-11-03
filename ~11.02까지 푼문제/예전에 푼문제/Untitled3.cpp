#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n,k;
int dist[100001];
bool check[100001];

int main(){
	fastio;
	cin>>n>>k;
	
	queue<int> Q;
	Q.push(n);
	dist[n]=0;//방문 표시 & 거리저장.
	check[n]=true;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();	
		
		if(cur*2<=100000&&check[cur*2]==false){
			Q.push(cur*2);//순간이동인 경우 우선순위가 더 높음-> 무조건 먼저처리! 
			dist[cur*2]=dist[cur];
			check[cur*2]=true;
		}
		if(cur-1>=0&&check[cur-1]==false){
			Q.push(cur-1);
			dist[cur-1]=dist[cur]+1;
			check[cur-1]=true;
		}
		if(cur+1<=100000&&check[cur+1]==false){
			Q.push(cur+1);
			dist[cur+1]=dist[cur]+1;
			check[cur+1]=true;
		}
	}
	cout<<dist[k];
}

