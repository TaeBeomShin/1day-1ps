#include<iostream>
#include<queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
		int N;
	cin>>N;
	queue <int> q;
	for(int i=0;i<N;i++){
		string command;
		cin>>command;
//명령어 처리 push X, front,back, size, empty, top. 
//스택의 기본기능 구현. 
//push: 수를 집어 넣는다(full은 따로 생각안하는듯.)
//pop: 젤위의 수를 삭제 한다.(output이 따로없고, top을 실행한 후 pop을 하는 형태로 많이사용함.) 
//size : 스택의 크기를 반환한다.
//empty : 스택이 비어있으면 1 아니면 0을 반환한다.
//front : 스택의 가장  앞 수를 반환한다.(반환한후 삭제하지는 않는다.) 
//back : 스택의 가장  뒷  수를 반환한다.(반환한후 삭제하지는 않는다.) 
		if(command=="push"){
			int num;
			cin>>num;
			q.push(num);
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
		else if(command=="pop"){
			if(!q.empty()){
				cout<<q.front()<<"\n";
				q.pop();
			}
			else{
				cout<<"-1"<<"\n";
			}
		}
	}
	
	return 0;
} 
