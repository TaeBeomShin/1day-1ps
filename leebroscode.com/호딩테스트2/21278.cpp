#include<bits/stdc++.h>
using namespace std;

int n,m;
int dist[101][101];
vector<int> chicken;
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		fill(dist[i],dist[i]+n,1e9);
		
	for(int i=0;i<m;i++){
		int s,e;cin>>s>>e;s--;e--;
		dist[s][e]=1;
		dist[e][s]=1;
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	
	for(int i=0;i<n;i++){//치킨집의 위치 결정. 
		if(i<2) chicken.push_back(0);
		else chicken.push_back(1);
	}
	
	int a,b,ans=1e9;
	do{
		int result=0;
		vector<int> position;
		
		for(int i=0;i<n;i++){
			if(chicken[i]==0) position.push_back(i);
		}
		
		for(int i=0;i<n;i++){
			if(i==position[0]||i==position[1]) continue;
			result+=min(2*dist[i][position[0]],2*dist[i][position[1]]);
		}
		if(result<ans){
			ans=result;
			a=position[0];
			b=position[1];
		}
	}while(next_permutation(chicken.begin(),chicken.end()));
	
	if(a>b) swap(a,b);
	cout<<a+1<<" "<<b+1<<" "<<ans;
}
