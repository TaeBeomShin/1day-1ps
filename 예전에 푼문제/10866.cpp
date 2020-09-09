#include<iostream>
#include<deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
		int N;
	cin>>N;
	deque <int> q;
	for(int i=0;i<N;i++){
		string command;
		cin>>command;
//덱: 양쪽에서 자료를 넣었다 뺏다할 수 있는 자료구조.
//push_front, push_back, pop_front, pop_back, size, empty, front, back
//의 명령어를 사용한다. 
		if(command=="push_front"){
			int num;
			cin>>num;
			q.push_front(num);
		}
		else if(command=="push_back"){
			int num;
			cin>>num;
			q.push_back(num);
		}
		else if(command=="front"){
			if(!q.empty())
				cout<<q.front()<<"\n";
			else cout<<"-1"<<"\n";
		}
		else if(command=="back"){
			if(!q.empty())
				cout<<q.back()<<"\n";
			else cout<<"-1"<<"\n";
		}
		else if(command=="size"){
			cout<<q.size()<<"\n";
		}
		else if(command=="empty"){
			cout<<q.empty()<<"\n";
		}
		else if(command=="pop_front"){
			if(!q.empty()){
				cout<<q.front()<<"\n";
				q.pop_front();
			}
			else{
				cout<<"-1"<<"\n";
			}
		}
		else if(command=="pop_back"){
			if(!q.empty()){
				cout<<q.back()<<"\n";
				q.pop_back();
			}
			else{
				cout<<"-1"<<"\n";
			}
		}
	}
	
	return 0;
} 
