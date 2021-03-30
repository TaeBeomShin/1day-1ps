#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

int t;

char oper[4]={'D','S','L','R'};

int DSLR(int num,char c){
	
	if(c=='D') num=2*num%10000;
	else if(c=='S') num=!num?9999:num-1;
	else if(c=='L') num=(10*num%10000)+num/1000;
	else if(c=='R') num=(num/10)+(num%10)*1000;
	
	return num;
}

int main(){
	fastio;cin>>t;
	
	int start,end;
	while(t--){
		
		bool visited[10000]={false,};
		queue<pair<int,string> > Q;

		cin>>start>>end;
		Q.push({start,""});
		visited[start]=true;
		
		while(!Q.empty()){
			auto cur=Q.front();Q.pop();
			int curv=cur.first;string curw=cur.second;
			if(curv==end){
				cout<<curw<<"\n"; 
				break;
			}
			
			for(int i=0;i<4;i++){
				char next_command=oper[i];
				int next_value=DSLR(curv,next_command);
				
				if(visited[next_value]) continue;
				
				Q.push({next_value,curw+next_command});
				visited[next_value]=true;
			}	
		}
		
		while(!Q.empty()) Q.pop();
	}
}
