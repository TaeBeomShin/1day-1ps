#include<bits/stdc++.h>
using namespace std;

int t[11]={0,};
bool check[11];
int main(){
	int n,w,l;//n:다리를 건너는 트럭의 수,w:다리 길이,l:다리의 최대하중.
	cin>>n>>w>>l;
	int max=n;
	queue <int> trucks;
	queue <int> current;
	while(n--){
		int truck;
		cin>>truck;
		trucks.push(truck);
	}

	
	int count=0;
	int currentsum=0;
	int number=1;//다리에 올라간 트럭의 순서. 
	int pass=0;

	while(true){//모든 트럭이 지나갈 때까지.
		//현재 다리에 있는 차들이 언제 빠져나가는지 카운트해야함.
		//빠져나가야할 때가 됬다면 처리해줘야함. 
		count++;
		for(int i=1;i<=10;i++){
			if(check[i]==true) t[i]++;
		}
		 
		if(currentsum+trucks.front()<=l&&!trucks.empty()){//더 진입해도 되는 경우. 
		 	current.push(trucks.front());
		 	currentsum+=trucks.front();
		 	check[number]=true;//몇번째 트럭인지 체크한다. 
		 	t[number]=1;//새로 들어간 트럭의 시간을 잰다.
		 	number++;
		 	trucks.pop();
		}
		for(int i=1;i<=number;i++){
		 	if(t[i]==w){
			 //다리를 빠져나갈 때가 되었다면. current에서 제거, 시간을 0으로. 
		 		currentsum-=current.front();
				current.pop();
				check[i]=false;
		 		t[i]=0;
		 		pass++;
			 }
		 }
		 if(pass==max){
		 	break;
		 }
	}
	cout<<count+1;
	
	return 0;
}
