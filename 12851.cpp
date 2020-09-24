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
			//������ �Ѿ�� ���. 
			if(result[next]==0){//�ѹ��� �湮���� �ʾ��� ��. 
				Q.push(next);
				dist[next]=dist[cur]+1;
				result[next]=result[cur];
			}else if(dist[next]==dist[cur]+1){
			//�湮 �ߴµ�, �Ÿ����� ������ ���.
				result[next]+=result[cur]; 
			} 
		}
	}
	cout<<dist[k]<<"\n"<<result[k];
}
