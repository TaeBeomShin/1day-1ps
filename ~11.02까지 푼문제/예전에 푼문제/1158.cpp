#include<iostream>
#include<queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int N,M;
	queue<int> q;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
		q.push(i);
		
	cout <<"<";
	while(q.size()){//queue가 빌때까지 진행 
		if(q.size()==1){
			cout<<q.front()<<">";
			q.pop();
			break;
		}
		for(int i=1;i<M;i++){
			//M번째 값이 나올때까지, 앞부분을 차례로 뒤로보내줌. 
			q.push(q.front());
			q.pop();
		}
		cout<<q.front()<<", ";
		q.pop();//M번째값을 출력하고 q에서 제거함. 
	}
	return 0;
}
