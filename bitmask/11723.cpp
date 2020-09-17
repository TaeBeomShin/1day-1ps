#include<iostream>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int main(){
	//메모리 제한이 4mb이므로 비트 마스크를 이용한다. 
	//비트마스클 사용하는 이유. 메모리 소모가 매우 적기때문이다. 
	fastio;
	int x=0;//
	int M;cin>>M;
	for(int i=0;i<M;i++){
		int num;string command;cin>>command;
		if(command=="add"){
			cin>>num;
			x|=(1<<num);
		}
		else if(command=="remove"){
			cin>>num;
			x&=~(1<<num);
		}
		else if(command=="check"){
			cin>>num;
			if(x&(1<<num)) cout<<"1\n";
			else cout<<"0\n";
		}else if(command=="toggle"){
			cin>>num;
			if(x&(1<<num)) x&=~(1<<num);
			else x|=(1<<num);
		}else if(command=="all"){
	 		x=(1<<21)-1;
		}else if(command=="empty") x=0;
	} 
}
