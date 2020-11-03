#include<bits/stdc++.h>
#define X first;
#define Y second;
#define MAX 1000000000
using namespace std;

int main(){
	int a,b;cin>>a>>b;
	bool finish= false;
	
	queue<pair<int,int> > Q;
	Q.push({a,1});
	
	while(!Q.empty()){
		int num=Q.front().X;int count=Q.front().Y;
		Q.pop();
		
		if(num==b){
			cout<<count;
			finish=true;
			break;
		}
		if(num*2<=b) Q.push({num*2,count+1});
		if(num<=MAX/10&&num*10+1<=b) Q.push({num*10+1,count+1});
	}
	if(!finish) cout<<-1; 
}
