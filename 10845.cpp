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
//��ɾ� ó�� push X, front,back, size, empty, top. 
//������ �⺻��� ����. 
//push: ���� ���� �ִ´�(full�� ���� �������ϴµ�.)
//pop: ������ ���� ���� �Ѵ�.(output�� ���ξ���, top�� ������ �� pop�� �ϴ� ���·� ���̻����.) 
//size : ������ ũ�⸦ ��ȯ�Ѵ�.
//empty : ������ ��������� 1 �ƴϸ� 0�� ��ȯ�Ѵ�.
//front : ������ ����  �� ���� ��ȯ�Ѵ�.(��ȯ���� ���������� �ʴ´�.) 
//back : ������ ����  ��  ���� ��ȯ�Ѵ�.(��ȯ���� ���������� �ʴ´�.) 
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
