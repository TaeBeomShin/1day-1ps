#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int n,k;
int dist[100001];
int result[100001];

int main(){
	fastio;
	cin>>n>>k;
	
	queue<int> Q;
	Q.push(n);
	dist[n]=0;
	result[n]=1;
	
	while(!Q.empty()){
		int cur=Q.front();Q.pop();
		
		int arr[3]={cur-1,cur+1,cur*2};
		
		for(int i=0;i<3;i++){
			int next=arr[i];
			if(next<0||next>100000) continue;
			//범위를 넘어서는 경우. 
			if(result[next]==0){//한번도 방문하지 않았을 때. 
				Q.push(next);
				dist[next]=dist[cur]+1;
				result[next]=result[cur];
			}else if(dist[next]==dist[cur]+1){
			//방문 했는데, 거리값이 동일한 경우.
				result[next]+=result[cur]; 
			} 
		}
	}
	cout<<dist[k]<<"\n"<<result[k];
}
