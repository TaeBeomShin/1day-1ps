#include<bits/stdc++.h>
using namespace std;

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int main(){
	int t,l,sx,sy,ex,ey; 
	cin>>t;
	
	while(t--){
		
		bool visited[301][301]={0,};
		cin>>l>>sx>>sy>>ex>>ey;
		
		queue <pair<int, pair<int,int> > > q;
		q.push(make_pair(0,make_pair(sy,sx)));
		visited[sy][sx]++;
		
		while(!q.empty()){
			int y=q.front().second.first;
			int x=q.front().second.second;
			int count =q.front().first;
			q.pop();
			
			if(y==ey&&x==ex){
				cout<<count<<"\n";
				break;
			}
			for(int i=0;i<8;i++){
				int ny=y+dy[i];
				int nx=x+dx[i];
				
				if(ny<0||ny>=l||nx<0||nx>=l) continue;
				
				if(visited[ny][nx]) continue;
				
				visited[ny][nx]++;
				q.push(make_pair(count+1,make_pair(ny,nx)));
			}
		}
		
	}
}
