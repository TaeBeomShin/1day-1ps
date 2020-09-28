#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;
int main(){
	fastio;
	int n;cin>>n;
	queue<int> q;
	while(n--){
		string command;cin>>command;
		int num;
		if(command=="push"){
			cin>>num;
			q.push(num);
		}
		else if(command=="pop"){
			(q.empty())?cout<<-1<<"\n":cout<<q.front()<<"\n";
			if(!q.empty()) q.pop();	
		}
		else if(command=="size"){
			cout<<q.size()<<"\n";
		}
		else if(command=="empty"){
			(q.empty())?cout<<"1\n":cout<<"0\n";
		}
		else if(command=="front"){
			(q.empty())?cout<<"-1\n":cout<<q.front()<<"\n";
		}
		else if(command=="back"){
			(q.empty())?cout<<"-1\n":cout<<q.back()<<"\n";
		}
	}
}
